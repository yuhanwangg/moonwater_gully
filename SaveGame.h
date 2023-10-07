#ifndef SAVEGAME_H
#define SAVEGAME_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "Inventory.h"
#include "Player.h"
#include "tile.h"

class SaveGame {
 private:
  int flag;

 protected:
  // saving game
  SaveGame() {
    saveFile.open("save.txt", std::ios::out | std::ios::in);
    if (!saveFile) {
      std::cout << "File could not be opened for saving." << std::endl;
    }
  }

  ~SaveGame() {
    if (saveFile.is_open()) {
      saveFile.close();
    }
  }

  void SaveGame(tile* background, Inventory* inventory, Player* player) {
    // create text file
    std::fstream saveFile("save.txt");
    if (!saveFile) {
      std::cout << "file could not be saved";
      std::cout << "\n";
    }
    flag = 0;

    // save a vector of tiles
    for (int i = 0; i < background->get_size(); i++) {
      saveFile << background[i].get_className() << ",";
      saveFile << background[i].get_growthStage() << ",";
      saveFile << background[i].get_hydrationLevel() << ",";
      flag += 3;
    }

    // save inventory count of each item
    std::vector<int*> temp_inv = inventory;
    for (int i = 0; temp_inv->get_size(); i++) {
      saveFile << temp_inv[i] << ",";
      flag++;
    }

    // save player shell number
    saveFile << player->get_shells() << std::endl;
    flag++;
    saveFile.close();
  }

  void loadGame() {}
};
#endif