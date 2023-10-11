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
 protected:
  std::fstream saveFile;

 public:
  // saving game
  SaveGame() {
    // saveFile.open("save.txt", std::ios::out);
    // if (!saveFile.is_open()) {
    //   std::cout << "File could not be opened for saving." << std::endl;
    // }
  }

  SaveGame(std::vector<tile*> background, int size, Inventory* inventory,
           Player* player, Day* day) {
    saveFile.open("save.txt", std::ios::out);
    if (!saveFile.is_open()) {
      std::cout << "File could not be opened for saving." << std::endl;
      return;  // Handle the error and return if the file couldn't be opened.
    }

    // save a vector of tiles
    for (int i = 0; i < size; i++) {
      saveFile << background[i]->get_className()
               << ",";  // comma used as a deliminator when using get_line()
      saveFile << background[i]->get_growthStage() << ",";
      saveFile << background[i]->get_hydrationLevel() << ",";
      saveFile << "newTile";  // in file when reading through to load, check if
                              // newTile then get next tile to load info
    }

    saveFile << "\n";
    saveFile << "inventory: ";  // in file， check when u see "inventory"
    // save inventory count of each item
    for (int i = 0; i < inventory->get_inventorySize(); i++) {
      saveFile << inventory->get_inventory()[i] << ",";
    }
    std::cout << "shellNumber";

    // save player shell number
    saveFile << player->get_shells() << std::endl;

    // save day number

    std::cout << "DayCount";
    saveFile << day->get_dayCount() << std::endl;

    // save time left in day
    std::cout << "DayTime";
    saveFile << day->get_timeInSec() << std::endl;

    saveFile.close();
  }

  void loadGame() {}

  // getter and setter
  // void open_saveFile() { saveFile.open(); }

  // ~SaveGame() {
  //   if (saveFile.is_open()) {
  //     saveFile.close();
  //   }
  // }
};
#endif