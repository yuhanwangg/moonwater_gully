#ifndef SAVEGAME_H
#define SAVEGAME_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Day.h"
#include "Inventory.h"
#include "Player.h"
#include "tile.h"
using namespace sf;

class SaveGame {
 protected:
  std::fstream saveFile;
  RectangleShape* loadAsk;
  bool loadAskVisible;
  int x, y;
  Text confirm[2];
  int selection;
  Font font;
  std::vector<int> temp_inv;

 public:
  // saving game
  SaveGame() {
    // saveFile.open("save.txt", std::ios::out);
    // if (!saveFile.is_open()) {
    //   std::cout << "File could not be opened for saving." << std::endl;
    // }
  }

  SaveGame(int len, int width) {
    // writing first pop up when game is booted up
    x = 150;
    y = 150;
    selection = 0;

    loadAskVisible = true;
    loadAsk = new RectangleShape(Vector2f(300, 150));
    loadAsk->setFillColor(Color::Green);
    loadAsk->setPosition(x, y);

    // loading font
    font.loadFromFile("textures/font_texture/TTF/dogica.ttf");
    if (!font.loadFromFile("textures/font_texture/TTF/dogica.ttf")) {
      std::cout << "error loading font" << std::endl;  // error testing
    }

    // creating options for text
    confirm[0].setFont(font);
    confirm[0].setString("load last save");
    confirm[0].setCharacterSize(15);
    confirm[0].setFillColor(Color::White);
    confirm[0].setPosition(x + 15, y + 15);

    confirm[1].setFont(font);
    confirm[1].setString("start new game");
    confirm[1].setCharacterSize(15);
    confirm[1].setFillColor(Color::White);
    confirm[1].setPosition(x + 15, y + 100);

    confirm[selection].setFillColor(Color::Yellow);  // use to navigate
  }

  void scrollLoad() {
    if (selection + 1 <= 2) {
      confirm[selection].setFillColor(Color::White);
      selection++;
      if (selection > 1) {
        selection = 0;
      }
      if (selection == 0) {
        confirm[selection].setFillColor(Color::Yellow);
      }

      confirm[selection].setFillColor(Color::Yellow);
    }
  }

  void drawLoad(RenderWindow* win) {
    win->draw(*loadAsk);
    for (int i = 0; i < 2; i++) {
      win->draw(confirm[i]);
    }
  }

  void save(std::vector<tile*> background, int size, Inventory* inventory,
            Player* player, Day* day) {
    saveFile.open("save.txt", std::ios::out);
    if (!saveFile.is_open()) {
      std::cout << "File could not be opened for saving." << std::endl;
      return;  // Handle the error and return if the file couldn't be opened.
    }

    saveFile << "newTile,";  // in file when reading through to load, check if
                             // newTile then get next tile to load info
    // save a vector of tiles
    for (int i = 0; i < size; i++) {
      saveFile << background[i]->get_className()
               << ",";  // comma used as a deliminator when using get_line()
      saveFile << background[i]->get_growthStage() << ",";
      saveFile << background[i]->get_hydrationLevel() << ",";
    }

    saveFile << "\n";
    saveFile << "inventory,";  // in file， check when u see "inventory"
    // save inventory count of each item
    for (int i = 0; i < (inventory->get_inventorySize()); i++) {
      saveFile << inventory->get_inventory()[i] << ",";
    }
    saveFile << "shellNumber,";

    // save player shell number
    saveFile << player->get_shells() << std::endl;

    // save day number

    saveFile << "DayCount,";
    saveFile << day->get_dayCount() << std::endl;

    // save time left in day
    saveFile << "DayTime,";
    saveFile << day->get_timeInSec() << std::endl;

    saveFile.close();
    std::cout << "Game saved,";
  };

  void loadGame(std::vector<tile*> background, Inventory* inventory,
                Player* player, Day* day) {
    saveFile.open("save.txt", std::ios::in);

    if (!saveFile.is_open()) {
      std::cout << "File could not be opened for loading." << std::endl;
      return;  // error handling
    }

    int itemCount = 0;  // tracking inventory
    std::string line;
    bool readTiles = false;  // tracking tiles
    while (std::getline(saveFile, line)) {
      if (line == "newTile,") {
        readTiles = true;
        continue;
      } else if (line == "inventory,") {
        // when to read inventory
        readTiles = false;
        itemCount = 0;
        continue;
      }

      if (readTiles == true) {
        // create the tile objects
        std::vector<std::string> tileData;
        size_t pos = 0;
        while ((pos = line.find(',')) != std::string::npos) {
          tileData.push_back(line.substr(0, pos));
          line.erase(0, pos + 1);
        }

        if (tileData.size() >= 3 && itemCount < background.size()) {
          std::string className = tileData[0];
          int growthStage = std::stoi(tileData[1]);
          int hydrationLevel = std::stoi(tileData[2]);

          // updating tile objects from tile data
          background[itemCount]->set_className(className);
          background[itemCount]->set_hydrationLevel(hydrationLevel);

          itemCount++;
        }
      } else {
        if (line.find("shellNumber,") != std::string::npos) {
          // setting shell number
          line = line.substr(12);
          int shells = std::stoi(line);
          player->set_shells(shells);
        } else if (line.find("DayCount,") != std::string::npos) {
          // reading and setting day
          line = line.substr(10);
          int dayCount = std::stoi(line);
          day->set_dayCount(dayCount);
        } else if (line.find("DayTime,") != std::string::npos) {
          // reading day time
          line = line.substr(9);
          int timeInSec = std::stoi(line);
          day->set_timeInSec(timeInSec);
        } else if (line.find("inventory,") != std::string::npos) {
          std::istringstream iss(line);
          std::string item;
          temp_inv.clear();
          while (std::getline(iss, item, ',') && itemCount < 10) {
            // Parse the inventory item as an integer
            int inventoryItem = std::stoi(item);
            // adding to temp inv
            temp_inv.push_back(inventoryItem);
            itemCount++;
          }
          inventory->set_inventory(temp_inv);
        }
      }
    }

    // closing and checking the load worked
    saveFile.close();
    std::cout << "LoaDING WORKS." << std::endl;
  }

  void clearFile() {
    saveFile.open("save.txt", std::ofstream::out | std::ofstream::trunc);
    saveFile.close();
    std::cout << "cleared successfully" << std::endl;
  }

  // getters and setters
  bool get_loadVisibility() { return loadAskVisible; }
  void set_loadVisibility(bool visi) { loadAskVisible = visi; }
  int get_select() { return selection; }
  void set_select(int sel) { selection = sel; }
};
#endif