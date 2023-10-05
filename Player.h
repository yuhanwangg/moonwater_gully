#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include <cmath>
#include <typeinfo>
#include <unordered_map>

#include "Blueberry.h"
#include "Carrot.h"
#include "Inventory.h"
#include "Plant.h"
#include "Player.h"
#include "Potato.h"
#include "Strawberry.h"
// #include "PlayerInteraction.h"

class Player {
 private:
  std::string name;
  CircleShape* body;
  int x, y;
  float speed;
  int shells;
  // Inventory* inventory = new Inventory(550, 50);

  std::unordered_map<std::string, int> plantLocationMap{
      {"Carrot", 9}, {"Potato", 7}, {"Strawberry", 5}, {"Blueberry", 3}};

 public:
  Player(int r, int _x, int _y) {
    body = new CircleShape();
    x = _x;
    y = _y;
    shells = 5000;
    speed = 0.2;

    body->setRadius(r);
    body->setFillColor(Color::Blue);
    body->setOrigin(r / 2, r / 2);
    body->setPosition(x, y);
  }

  void draw(RenderWindow* win) {
    win->draw(*body);
    // inventory->drawInventory(win);
  }

  // Seeding plant

  void seedPlant(int seedType, std::vector<tile*>* backgroundTiles) {
    int player_x = (floor(body->getPosition().x / 50));
    int player_y = (floor(body->getPosition().y / 50));

    switch (seedType) {
      case 2:  // type 2 is blueberry seeds in inventory position 2
      {
        // create a new bluebbery tile (in the heap) with cooridnates of
        // player position and set blueberry as a pointer to the blueberry
        // tile
        Blueberry* blueberry = new Blueberry(player_x * 50, player_y * 50);
        // remove old tile from vector and replace with new carrot tile
        delete (*backgroundTiles)[player_x * 12 + player_y];
        // sets the current tile player is on to be a carrot tile
        (*backgroundTiles)[player_x * 12 + player_y] = blueberry;
        break;
      }

      case 4:  // type 4 is strawberry seeds in inventory position 4
      {
        // create a new strawberry tile (in the heap) with cooridnates of
        // player position and set strawberry as a pointer to the
        // strawberry tile
        Strawberry* strawberry = new Strawberry(player_x * 50, player_y * 50);
        // remove old tile from vector and replace with new carrot tile
        delete (*backgroundTiles)[player_x * 12 + player_y];
        // sets the current tile player is on to be a carrot tile
        (*backgroundTiles)[player_x * 12 + player_y] = strawberry;
        break;
      }

      case 6:  // type 6 is potato seeds in inventory position 6
      {
        // create a new potato tile (in the heap) with cooridnates of
        // player position and set potato as a pointer to the potato tile
        Potato* potato = new Potato(player_x * 50, player_y * 50);
        // remove old tile from vector and replace with new carrot tile
        delete (*backgroundTiles)[player_x * 12 + player_y];
        // sets the current tile player is on to be a carrot tile
        (*backgroundTiles)[player_x * 12 + player_y] = potato;
        break;
      }

      case 8:  // type 8 is carrot seeds in inventory position 8
      {
        // create a new carrot tile (in the heap) with cooridnates of
        // player position and set carrot as a pointer to the carrot tile
        Carrot* carrot = new Carrot(player_x * 50, player_y * 50);
        // remove old tile from vector and replace with new carrot tile
        delete (*backgroundTiles)[player_x * 12 + player_y];
        // sets the current tile player is on to be a carrot tile
        (*backgroundTiles)[player_x * 12 + player_y] = carrot;
        break;
      }

      default:
        std::cout << "error: could not plant as type was invalid" << std::endl;
    };
  }

  // void seedPlant(int seedType, std::vector<tile*>* backgroundTiles) {
  //   int player_x = (floor(body->getPosition().x / 50) * 50);
  //   int player_y = (floor(body->getPosition().y / 50) * 50);

  //   for (int i = 0; i < 144; i++) {
  //     tile* currentTile = (*backgroundTiles)[i];  // Access the current tile
  //                                                 // pointer in the vector

  //     // determine which tile the player is on
  //     if (currentTile->get_x() == player_x &&
  //         currentTile->get_y() == player_y) {
  //       if (currentTile->get_isPlantable() == true) {
  //         switch (seedType) {
  //           case 2:  // type 2 is blueberry seeds in inventory position 2
  //           {
  //             // create a new bluebbery tile (in the heap) with cooridnates
  //             of
  //             // player position and set blueberry as a pointer to the
  //             blueberry
  //             // tile
  //             Blueberry* blueberry = new Blueberry(player_x, player_y);
  //             // remove old tile from vector and replace with new carrot tile
  //             delete currentTile;
  //             // sets the current tile player is on to be a carrot tile
  //             (*backgroundTiles)[i] = blueberry;
  //             break;
  //           }

  //           case 4:  // type 4 is strawberry seeds in inventory position 4
  //           {
  //             // create a new strawberry tile (in the heap) with cooridnates
  //             of
  //             // player position and set strawberry as a pointer to the
  //             // strawberry tile
  //             Strawberry* strawberry = new Strawberry(player_x, player_y);
  //             // remove old tile from vector and replace with new carrot tile
  //             delete currentTile;
  //             // sets the current tile player is on to be a carrot tile
  //             (*backgroundTiles)[i] = strawberry;
  //             break;
  //           }

  //           case 6:  // type 6 is potato seeds in inventory position 6
  //           {
  //             // create a new potato tile (in the heap) with cooridnates of
  //             // player position and set potato as a pointer to the potato
  //             tile Potato* potato = new Potato(player_x, player_y);
  //             // remove old tile from vector and replace with new carrot tile
  //             delete currentTile;
  //             // sets the current tile player is on to be a carrot tile
  //             (*backgroundTiles)[i] = potato;
  //             break;
  //           }

  //           case 8:  // type 8 is carrot seeds in inventory position 8
  //           {
  //             // create a new carrot tile (in the heap) with cooridnates of
  //             // player position and set carrot as a pointer to the carrot
  //             tile Carrot* carrot = new Carrot(player_x, player_y);
  //             // remove old tile from vector and replace with new carrot tile
  //             delete currentTile;
  //             // sets the current tile player is on to be a carrot tile
  //             (*backgroundTiles)[i] = carrot;
  //             break;
  //           }

  //           default:
  //             std::cout << "error: could not plant as type was invalid"
  //                       << std::endl;
  //         };
  //         break;  // stops looping through for loop
  //       }
  //     }
  //   }
  //   return;
  // }

  // Water plant

  void waterPlant(std::vector<tile*>* backgroundTiles) {
    // changes the x and y coordinates of the player to valid tile positions
    int player_x = (floor(body->getPosition().x / 50));
    int player_y = (floor(body->getPosition().y / 50));

    (*backgroundTiles)[player_x * 12 + player_y]->set_hydrationLevel(1);
    return;
  };

  void harvestPlant(std::vector<tile*>* backgroundTiles, Inventory* inventory){

  // inventory){ std::cout << (*backgroundTiles)[1]->get_className() <<
  // std::endl;

  // Cha

  // Oi Mischa, put this in inventory so you don't have so many getters and
  // setters: void set_anyCount(std::string name, int amount) {
  // inventoryMap[name] = amount}

  // Use a map once you have the type of function

    int player_x = (floor(body->getPosition().x / 50));
    int player_y = (floor(body->getPosition().y / 50));

    // Getting yield and inventory position
    int plantYield;
    int plantPos;

    if((*backgroundTiles)[player_x * 12 + player_y]->get_className() == "tile"){
      std::cout << "Land cannot be harvested" << std::endl;
      return;
    }
    // else if((*backgroundTiles)[player_x * 12 + player_y]->get_growthStage() != (*backgroundTiles)[player_x * 12 + player_y]->get_growTime()){
    //     std::cout << "Please wait until plant is fully grown" << std::endl;
    //     return;
    // }
    // else if((*backgroundTiles)[player_x * 12 + player_y]->get_className() == "Blueberry" ||
    //  (*backgroundTiles)[player_x * 12 + player_y]->get_className() == "Strawberry" &&
    //   inventory->get_inventoryIndex() != 1){
    //     std::cout << "Must hold gloves to harvest these plants" << std::endl;
    //     return;
    // }
    // else if((*backgroundTiles)[player_x * 12 + player_y]->get_className() == "Carrot" ||
    //  (*backgroundTiles)[player_x * 12 + player_y]->get_className() == "Potato" &&
    //   inventory->get_inventoryIndex() != 0){
    //     std::cout << "Must hold a shovel to harvest these plants" << std::endl;
    //     return;
    // }
    

    plantYield = (*backgroundTiles)[player_x * 12 + player_y]->harvestYield();
    plantPos = plantLocationMap[(*backgroundTiles)[player_x * 12 + player_y]->get_className()];

    // Adding plants to the Inventory

    std::cout << plantYield << std::endl;

    inventory->set_fromPos(plantPos, inventory->get_fromPos(plantPos) + plantYield);

    // resetting position as a tile

    delete (*backgroundTiles)[player_x * 12 + player_y];

    (*backgroundTiles)[player_x * 12 + player_y] = new tile(player_x * 50,player_y * 50);

  }

  // kill plant (becaues it hasn't been watered)
  // void killPlant(std::vector<tile*>* backgroundTiles) {
  //   for (int i = 0; i < 144; i++) {
  //       tile* currentTile = (*backgroundTiles)[i];  // Access the current
  //       tile
  //                                                   // pointer in the vector

  //       // determine which tile the player is on
  //       if (currentTile->get_hydrationLevel() < 0) {
  //           delete currentTile;
  //           tile* farmland = new tile(currentTile->get_x(),
  //           currentTile->get_y());
  //           (*backgroundTiles)[i] = farmland;
  //       }
  //   }
  // };

  // movement of the player
  void move_right() { body->move(speed, 0); }
  void move_left() { body->move(-speed, 0); }
  void move_up() { body->move(0, -speed); }
  void move_down() { body->move(0, speed); }

  // getters and setters
  // std::vector<int> get_inventory() { return inventory->get_inventory(); }
  int get_x() { return body->getPosition().x; }
  int get_y() { return body->getPosition().y; }

  void add_80shells() { shells += 80; }
  void add_100shells() { shells += 100; }
  void add_120shells() { shells += 120; }
  void add_200shells() { shells += 200; }

  void subtract_50shells() { shells -= 50; }
  void subtract_70shells() { shells -= 70; }
  void subtract_400shells() { shells -= 400; }
  void subtract_150shells() { shells -= 150; }

  int get_shells() { return shells; }
  void set_shells(int shell_no) { shells = shell_no; }
};

#endif