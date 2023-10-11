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

    saveFile << "newTile";  // in file when reading through to load, check if
                            // newTile then get next tile to load info
    // save a vector of tiles
    for (int i = 0; i < size; i++) {
      saveFile << background[i]->get_className()
               << ",";  // comma used as a deliminator when using get_line()
      saveFile << background[i]->get_growthStage() << ",";
      saveFile << background[i]->get_hydrationLevel() << ",";
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
  };

  void loadGame(std::vector<tile*>& background, Inventory* inventory,
                Player* player, Day* day) {
    saveFile.open("save.txt", std::ios::in);

    if (!saveFile.is_open()) {
      std::cout << "File could not be opened for loading." << std::endl;
      return;  // Handle the error and return if the file couldn't be opened.
    }

    std::string line;
    bool readTiles = false;  // To track when to start reading tiles

    while (std::getline(saveFile, line)) {
      if (line == "newTile") {
        readTiles = true;
        continue;
      } else if (line == "inventory:") {
        // Start reading inventory
        readTiles = false;
        continue;
      }

      if (readTiles) {
        // Parse and create tile objects
        std::vector<std::string> tileData;
        size_t pos = 0;
        while ((pos = line.find(',')) != std::string::npos) {
          tileData.push_back(line.substr(0, pos));
          line.erase(0, pos + 1);
        }

        // Create and populate a tile instance
        if (tileData.size() >= 3) {
          std::string className = tileData[0];
          int growthStage = std::stoi(tileData[1]);
          int hydrationLevel = std::stoi(tileData[2]);

          // Create a new tile object and add it to the background vector
          tile* newTileObject =
              new tile(className, growthStage, hydrationLevel);
          background.push_back(newTileObject);
        }
      } else {
        if (line.find("shellNumber") != std::string::npos) {
          line = line.substr(11);  // Remove "shellNumber"
          int shells = std::stoi(line);
          player->set_shells(shells);
        } else if (line.find("DayCount") != std::string::npos) {
          line = line.substr(8);  // Remove "DayCount"
          int dayCount = std::stoi(line);
          day->set_dayCount(dayCount);
        } else if (line.find("DayTime") != std::string::npos) {
          line = line.substr(8);  // Remove "DayTime"
          int timeInSec = std::stoi(line);
          day->set_timeInSec(timeInSec);
        }
      }
    }

    // Close the file after loading
    saveFile.close();
  }
};
#endif