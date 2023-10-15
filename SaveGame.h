#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Blueberry.h"
#include "BuyMenu.h"
#include "Carrot.h"
#include "Day.h"
#include "Inventory.h"
#include "Menu.h"
#include "Player.h"
#include "Potato.h"
#include "SaveGame.h"
#include "SellMenu.h"
#include "Strawberry.h"
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

  void save(std::vector<tile*>& background, int size, Inventory* inventory,
            Player* player, Day* day) {
    saveFile.open("save.txt", std::ios::out);
    if (!saveFile.is_open()) {
      std::cout << "file could not be opened for saving." << std::endl;
      return;  // error handling
    }
    // in file when reading through to load, check
    // newTile then get next tile to load info
    // save a vector of tiles
    for (int i = 0; i < size; i++) {
      saveFile << "newTile,";

      saveFile << background[i]->get_className()
               << " ";  // comma used as a deliminator when using get_line()
      // get coordinates
      saveFile << background[i]->get_x() << " ";

      saveFile << background[i]->get_y() << " ";

      saveFile << background[i]->get_growthStage() << " ";

      saveFile << background[i]->get_hydrationLevel() << " ";

      saveFile << "\n";
    }

    // save inventory count of each item
    for (int i = 0; i < (inventory->get_inventorySize()); i++) {
      saveFile << "inventory,";  // in file， check when u see "inventory"
      saveFile << inventory->get_inventory()[i] << " ";
      saveFile << "\n";
    }

    saveFile << "shellNumber,";

    // save player shell number
    saveFile << player->get_shells();

    saveFile << "\n";  // line by line approach

    // save day number

    saveFile << "dayCount,";
    saveFile << day->get_dayCount();
    saveFile << "\n";  // line by line approach

    // save time left in day
    saveFile << "dayTime,";
    saveFile << day->get_timeInSec();
    saveFile << "\n";  // line by line approach

    saveFile.close();
    std::cout << "game saved,";  // if statement to check when to stop
  };

  void load(std::vector<tile*> background, Inventory* inventory, Player* player,
            Day* day) {
    std::ifstream saveFile("save.txt");

    if (!saveFile.is_open()) {
      std::cout << "File could not be opened for loading." << std::endl;
      return;  // Error handling
    }

    std::string line;
    // temporary background;
    std::vector<tile*> tempBg;
    // temporary inventory
    std::vector<int> tempInv;

    while (std::getline(saveFile, line)) {
      std::istringstream iss(line);
      std::string token;

      // split line via commas
      while (std::getline(iss, token, ',')) {
        // determine the data type based on the first token
        if (token == "newTile") {
          // reading in tile data
          int x, y, growthStage, hydrationLevel;
          std::string className;

          if (iss >> x >> y >> className >> growthStage >>
              hydrationLevel) {  // reads via line spaced
            // switch case to add tile to background
            if (className == "tile") {
              tile* newTile = new tile(x, y);
              newTile->set_hydrationLevel(hydrationLevel);

              std::cout << "tile created";
              tempBg.push_back(newTile);

            } else if (className == "Carrot") {
              Carrot* carrotTile = new Carrot(x, y);
              carrotTile->set_hydrationLevel(hydrationLevel);
              carrotTile->set_growthStage(growthStage);

              tempBg.push_back(carrotTile);

            } else if (className == "Potato") {
              Potato* potatoTile = new Potato(x, y);
              potatoTile->set_hydrationLevel(hydrationLevel);
              potatoTile->set_growthStage(growthStage);

              tempBg.push_back(potatoTile);

            } else if (className == "Strawberry") {
              Strawberry* strawberryTile = new Strawberry(x, y);
              strawberryTile->set_hydrationLevel(hydrationLevel);
              strawberryTile->set_growthStage(growthStage);

              tempBg.push_back(strawberryTile);

            } else if (className == "Blueberry") {
              Blueberry* blueberryTile = new Blueberry(x, y);
              blueberryTile->set_hydrationLevel(hydrationLevel);
              blueberryTile->set_growthStage(growthStage);

              tempBg.push_back(blueberryTile);
            }
          }
        } else if (token == "inventory") {
          // read into inventory
          int item;
          if (iss >> item) {
            // Add the item to the inventory
            tempInv.push_back(item);
          }
        } else if (token == "shellNumber") {
          // Read player shell number
          int shells;
          if (iss >> shells) {
            player->set_shells(shells);
          }
        } else if (token == "dayCount") {
          // Read day count
          int dayCount;
          if (iss >> dayCount) {
            day->set_dayCount(dayCount);
          }
        } else if (token == "dayTime") {
          // Read day time
          int dayTime;
          if (iss >> dayTime) {
            day->set_timeInSec(dayTime);
          }
        }
      }

      background = tempBg;
      inventory->set_inventory(tempInv);
    }

    saveFile.close();
    std::cout << "Game loaded." << std::endl;
  }

  // void load(std::vector<tile*>& background, Inventory* inventory,
  //           Player* player, Day* day) {
  //   std::ifstream saveFile("save.txt");

  //   if (!saveFile.is_open()) {
  //     std::cout << "File could not be opened for loading." << std::endl;
  //     return;  // Error handling
  //   }

  //   std::string line;
  //   std::vector<tile*> tempBg;
  //   std::vector<int> tempInv;
  //   int tempDayCount = -1;
  //   int tempDayTime = -1;

  //   while (std::getline(saveFile, line)) {
  //     std::istringstream iss(line);
  //     std::string token;

  //     while (std::getline(iss, token, ',')) {
  //       if (token == "tileClass") {
  //         std::string className;
  //         int x = -1, y = -1, growthStage = -1, hydrationLevel = -1;
  //         if (iss >> className >> token >> x >> token >> y >> token >>
  //             growthStage >> token >> hydrationLevel) {
  //           if (className == "tile") {
  //             tile* newTile = new tile(x, y);
  //             newTile->set_hydrationLevel(hydrationLevel);

  //             std::cout << "tile read";
  //             tempBg.push_back(newTile);
  //           } else if (className == "Potato") {
  //             Potato* potatoTile = new Potato(x, y);
  //             potatoTile->set_growthStage(growthStage);
  //             potatoTile->set_hydrationLevel(hydrationLevel);

  //             std::cout << "potato read";
  //             tempBg.push_back(potatoTile);
  //           } else if (className == "Carrot") {
  //             Carrot* carrotTile = new Carrot(x, y);
  //             carrotTile->set_growthStage(growthStage);
  //             carrotTile->set_hydrationLevel(hydrationLevel);

  //             std::cout << "carrot read";
  //             tempBg.push_back(carrotTile);
  //           } else if (className == "Strawberry") {
  //             Strawberry* strawberryTile = new Strawberry(x, y);
  //             strawberryTile->set_hydrationLevel(hydrationLevel);
  //             strawberryTile->set_growthStage(growthStage);

  //             std::cout << "strawberry read";
  //             tempBg.push_back(strawberryTile);

  //           } else if (className == "Blueberry") {
  //             Blueberry* blueberryTile = new Blueberry(x, y);
  //             blueberryTile->set_hydrationLevel(hydrationLevel);
  //             blueberryTile->set_growthStage(growthStage);

  //             tempBg.push_back(blueberryTile);
  //           }
  //         }
  //       } else if (token == "inventory") {
  //         int item = -1;
  //         if (iss >> item) {
  //           // Add the item to the inventory
  //           tempInv.push_back(item);
  //         }
  //       } else if (token == "shellNumber") {
  //         int shells = -1;
  //         if (iss >> shells) {
  //           player->set_shells(shells);
  //         }
  //       } else if (token == "dayCount") {
  //         if (iss >> tempDayCount) {
  //           // Do nothing here; we will set the day count after reading the
  //           day
  //           // time
  //         }
  //       } else if (token == "dayTime") {
  //         if (iss >> tempDayTime) {
  //           // Set the day time in your Day object
  //           day->set_timeInSec(tempDayTime);
  //           // Set the day count in your Day object (if it was loaded)
  //           if (tempDayCount != -1) {
  //             day->set_dayCount(tempDayCount);
  //           }
  //         }
  //       }
  //     }
  //   }

  //   // After reading the entire file, update the background
  //   background = tempBg;
  //   inventory->set_inventory(tempInv);

  //   saveFile.close();
  //   std::cout << "Game loaded." << std::endl;
  // }

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