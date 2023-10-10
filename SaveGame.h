#ifndef SAVEGAME_H
#define SAVEGAME_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "Day.h"
#include "Inventory.h"
#include "Player.h"
#include "tile.h"

class SaveGame {
 private:
  int flag;
  std::map<std::string, int> token;
  int tileCount;
  std::string tileName;
  std::fstream saveFile;

 public:
  // saving game
  SaveGame() {
    saveFile.open("save.txt", std::ios::out | std::ios::in);
    if (!saveFile) {
      std::cout << "File could not be opened for saving." << std::endl;
    }
  }

  // ~SaveGame() {
  //   if (saveFile.is_open()) {
  //     saveFile.close();
  //   }
  // }

  SaveGame(tile* background, Inventory* inventory, Player* player, Day* day) {
    // create text file
    std::fstream saveFile("save.txt");
    if (!saveFile) {
      std::cout << "file could not be saved";
      std::cout << "\n";
    }

    // save a vector of tiles
    for (int i = 0; i < background->get_size(); i++) {
      saveFile << background[i].get_className() << ",";
      saveFile << background[i].get_growthStage() << ",";
      saveFile << background[i].get_hydrationLevel() << ",";
      std::cout << "newTile";
      tileCount++;
    }

    std::cout << "inventory";

    // save inventory count of each item
    for (int i = 0; inventory.get_size(); i++) {
      saveFile << inventory[i] << ",";
    }
    std::cout << "shellNumber";

    // save player shell number
    saveFile << player->get_shells() << std::endl;

    // save day number

    std::cout << "DayCount";
    saveFile << day->get_dayCount() << std::endl;

    // save time left in day
    std::cout << "DayTime";
    saveFile << day->get_timeInSec();
    << std::endl;

    saveFile.close();
  }

  void loadGame() {}

  // getter and setter
  void open_saveFile() { save.open(); }
};
#endif