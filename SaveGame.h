#ifndef SAVEGAME_H
#define SAVEGAME_H
#include <json/json.h>

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
    Json::Value root;

    for (int i = 0; i < size; i++) {
      Json::Value tileData;
      tileData["class"] = background[i]->get_className();
      tileData["growthStage"] = background[i]->get_growthStage();
      tileData["hydrationLevel"] = background[i]->get_hydrationLevel();
      root["tiles"].append(tileData);
    }

    Json::Value inventoryData;
    for (int i = 0; i < inventory->get_inventorySize(); i++) {
      inventoryData.append(inventory->get_inventory()[i]);
    }
    root["inventory"] = inventoryData;

    root["shellNumber"] = player->get_shells();
    root["DayCount"] = day->get_dayCount();
    root["DayTime"] = day->get_timeInSec();

    std::ofstream saveFile("save.json");
    if (saveFile.is_open()) {
      Json::StreamWriterBuilder writer;
      writer["indentation"] = "  ";
      saveFile << Json::writeString(writer, root);
      saveFile.close();
      std::cout << "Game saved." << std::endl;
    } else {
      std::cout << "File could not be opened for saving." << std::endl;
    }
  }

  void load(std::vector<tile*>& background, Inventory* inventory,
            Player* player, Day* day) {
    std::ifstream loadFile("save.json");
    if (!loadFile.is_open()) {
      std::cout << "File could not be opened for loading." << std::endl;
      return;
    }

    Json::Value root;
    loadFile >> root;

    const Json::Value& tilesData = root["tiles"];
    for (int i = 0; i < tilesData.size() && i < background.size(); i++) {
      const Json::Value& tileData = tilesData[i];
      background[i]->set_className(tileData["class"].asString());
      background[i]->set_growthStage(tileData["growthStage"].asInt());
      background[i]->set_hydrationLevel(tileData["hydrationLevel"].asInt());
    }

    const Json::Value& inventoryData = root["inventory"];
    for (int i = 0; i < inventoryData.size(); i++) {
      inventory->set_inventoryItemAt(i, inventoryData[i].asInt());
    }

    player->set_shells(root["shellNumber"].asInt());
    day->set_dayCount(root["DayCount"].asInt());
    day->set_timeInSec(root["DayTime"].asInt());

    loadFile.close();
    std::cout << "Game loaded." << std::endl;
  }

  // void save(std::vector<tile*> background, int size, Inventory* inventory,
  //           Player* player, Day* day) {
  //   saveFile.open("save.txt", std::ios::out);
  //   if (!saveFile.is_open()) {
  //     std::cout << "File could not be opened for saving." << std::endl;
  //     return;  // Handle the error and return if the file couldn't be opened.
  //   }

  //   saveFile << "newTile,";  // in file when reading through to load, check
  //   if
  //                            // newTile then get next tile to load info
  //   // save a vector of tiles
  //   for (int i = 0; i < size; i++) {
  //     saveFile << background[i]->get_className()
  //              << ",";  // comma used as a deliminator when using get_line()
  //     saveFile << background[i]->get_growthStage() << ",";
  //     saveFile << background[i]->get_hydrationLevel() << ",";

  //     saveFile << "done,";
  //   }

  //   saveFile << "inventory,";  // in file， check when u see "inventory"
  //   // save inventory count of each item
  //   for (int i = 0; i < (inventory->get_inventorySize()); i++) {
  //     saveFile << inventory->get_inventory()[i] << ",";
  //   }

  //   saveFile << "shellNumber,";

  //   // save player shell number
  //   saveFile << player->get_shells() << std::endl;

  //   // save day number

  //   saveFile << "DayCount,";
  //   saveFile << day->get_dayCount() << std::endl;

  //   // save time left in day
  //   saveFile << "DayTime,";
  //   saveFile << day->get_timeInSec() << std::endl;

  //   saveFile.close();
  //   std::cout << "Game saved,";
  // };

  // void load(std::vector<tile*>& background, Inventory* inventory,
  //           Player* player, Day* day) {
  //   std::ifstream loadFile("save.txt");

  //   if (!loadFile.is_open()) {
  //     std::cout << "File could not be opened for loading." << std::endl;
  //     return;
  //   }

  //   std::string line;
  //   std::string token;

  //   while (std::getline(loadFile, line)) {
  //     std::istringstream iss(line);
  //     iss >> token;

  //     if (token == "newTile,") {
  //       int position;
  //       int growthStage;
  //       int hydrationLevel;

  //       while (true) {
  //         iss >> position >> growthStage >> hydrationLevel;

  //         if (position >= background.size() || position < 0) {
  //           // Invalid position, skip this entry
  //           break;
  //         }

  //         // Update the tile at the specified position in the background
  //         vector
  //         // background[position]->set_growthStage(growthStage);
  //         background[position]->set_hydrationLevel(hydrationLevel);

  //         std::cout << position;

  //         std::string delimiter;
  //         iss >> delimiter;

  //         if (delimiter == "done") {
  //           break;  // End of tile entry
  //         }

  //         std::cout << "complete tile entry";
  //       }
  //     } else if (token == "inventory,") {
  //       int item;
  //       int i = 0;
  //       while (iss >> item) {
  //         inventory->set_inventoryItemAt(i, item);
  //         i++;
  //       }
  //     } else if (token == "shellNumber,") {
  //       int shells;
  //       iss >> shells;
  //       player->set_shells(shells);
  //     } else if (token == "DayCount,") {
  //       int dayCount;
  //       iss >> dayCount;
  //       day->set_dayCount(dayCount);
  //     } else if (token == "DayTime,") {
  //       int dayTime;
  //       iss >> dayTime;
  //       day->set_timeInSec(dayTime);
  //     }
  //   }

  //   loadFile.close();
  //   std::cout << "Game loaded." << std::endl;
  // }

  //   // closing and checking the load worked
  //   saveFile.close();
  //   std::cout << "LoaDING WORKS." << std::endl;
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