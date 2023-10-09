#ifndef PLAYERINTERACTION_H
#define PLAYERINTERACTION_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Blueberry.h"
#include "Carrot.h"
#include "Plant.h"
#include "Player.h"
#include "Potato.h"
#include "Strawberry.h"
#include "TextBox.h"
#include "tile.h"

class PlayerInteraction {
 protected:
  // std::vector<Carrot*> carrotVector;
  // std::vector<Potato*> potatoVector;

 public:
  PlayerInteraction(){};

  void seedPlant(
      int seedType, Player p,
      std::vector<tile*>*
          backgroundTiles) {  // takes in an int which represents the seed type
                              // (from the selected item in inventory), takes in
                              // an object player, and a pointer to a vector of
                              // pointers to tiles (a pointer to background
                              // tiles)

    // changes the x and y coordinates of the player to valid tile positions
    int playerX = (floor(p.get_x() / 50) * 50);
    int playerY = (floor(p.get_y() / 50) * 50);

    for (int i = 0; i < 144; i++) {
      tile* currentTile = (*backgroundTiles)[i];  // Access the current tile
                                                  // pointer in the vector

      // determine which tile the player is on
      if (currentTile->get_x() == playerX &&
          currentTile->get_y() == playerY) {
        if (currentTile->get_isPlantable() == true) {
          switch (seedType) {
            case 2:  // type 2 is blueberry seeds in inventory position 2
            {
              // create a new bluebbery tile (in the heap) with cooridnates of
              // player position and set blueberry as a pointer to the blueberry
              // tile
              Blueberry* blueberry = new Blueberry(playerX, playerY);
              // remove old tile from vector and replace with new carrot tile
              delete currentTile;
              // sets the current tile player is on to be a carrot tile
              (*backgroundTiles)[i] = blueberry;
              break;
            }

            case 4:  // type 4 is strawberry seeds in inventory position 4
            {
              // create a new strawberry tile (in the heap) with cooridnates of
              // player position and set strawberry as a pointer to the
              // strawberry tile
              Strawberry* strawberry = new Strawberry(playerX, playerY);
              // remove old tile from vector and replace with new carrot tile
              delete currentTile;
              // sets the current tile player is on to be a carrot tile
              (*backgroundTiles)[i] = strawberry;
              break;
            }

            case 6:  // type 6 is potato seeds in inventory position 6
            {
              // create a new potato tile (in the heap) with cooridnates of
              // player position and set potato as a pointer to the potato tile
              Potato* potato = new Potato(playerX, playerY);
              // remove old tile from vector and replace with new carrot tile
              delete currentTile;
              // sets the current tile player is on to be a carrot tile
              (*backgroundTiles)[i] = potato;
              break;
            }

            case 8:  // type 8 is carrot seeds in inventory position 8
            {
              // create a new carrot tile (in the heap) with cooridnates of
              // player position and set carrot as a pointer to the carrot tile
              Carrot* carrot = new Carrot(playerX, playerY);
              // remove old tile from vector and replace with new carrot tile
              delete currentTile;
              // sets the current tile player is on to be a carrot tile
              (*backgroundTiles)[i] = carrot;
              break;
            }

            default:
              std::cout << "error: could not plant as type was invalid"
                        << std::endl;
          };
          break;  // stops looping through for loop
        }
      }
    }
    return;
  };

  void waterPlant(Player p, std::vector<tile*>* backgroundTiles) {
    // changes the x and y coordinates of the player to valid tile positions
    int playerX = (floor(p.get_x() / 50) * 50);
    int playerY = (floor(p.get_y() / 50) * 50);

    for (int i = 0; i < 144; i++) {
      tile* currentTile = (*backgroundTiles)[i];  // Access the current tile
                                                  // pointer in the vector

      // determine which tile the player is on
      if (currentTile->get_x() == playerX &&
          currentTile->get_y() == playerY) {
        (*backgroundTiles)[i]->set_hydrationLevel(1);
        break;
      }
    }
    return;
  };

  void harvestPlant() { return; };
};

#endif