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

  // Doing the useless map
  Carrot* carrot = new Carrot(650, 650);
  Potato* potato = new Potato(650, 650);
  Strawberry* strawberry = new Strawberry(650,650);
  Blueberry* blueberry = new Blueberry(650,650);
  std::unordered_map<std::string, Plant*> plantMap{
    {"Carrot", carrot} , {"Potato", potato} , {"Strawberry", strawberry} , {"Blueberry", blueberry}};

 public:
  Player(int r, int _x, int _y) {
    body = new CircleShape();
    x = _x;
    y = _y;
    shells = 5000;
    speed = 2;

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
    int playerX = (floor(body->getPosition().x / 50));
    int playerY = (floor(body->getPosition().y / 50));
    if ((*backgroundTiles)[playerX * 12 + playerY]->get_isPlantable() == true) {
      switch (seedType) {
        case 2:  // type 2 is blueberry seeds in inventory position 2
        {
          // create a new bluebbery tile (in the heap) with cooridnates of
          // player position and set blueberry as a pointer to the blueberry
          // tile
          Blueberry* blueberry = new Blueberry(playerX * 50, playerY * 50);
          // remove old tile from vector and replace with new carrot tile
          delete (*backgroundTiles)[playerX * 12 + playerY];
          // sets the current tile player is on to be a carrot tile
          (*backgroundTiles)[playerX * 12 + playerY] = blueberry;
          break;
        }

        case 4:  // type 4 is strawberry seeds in inventory position 4
        {
          // create a new strawberry tile (in the heap) with cooridnates of
          // player position and set strawberry as a pointer to the
          // strawberry tile
          Strawberry* strawberry = new Strawberry(playerX * 50, playerY * 50);
          // remove old tile from vector and replace with new carrot tile
          delete (*backgroundTiles)[playerX * 12 + playerY];
          // sets the current tile player is on to be a carrot tile
          (*backgroundTiles)[playerX * 12 + playerY] = strawberry;
          break;
        }

        case 6:  // type 6 is potato seeds in inventory position 6
        {
          // create a new potato tile (in the heap) with cooridnates of
          // player position and set potato as a pointer to the potato tile
          Potato* potato = new Potato(playerX * 50, playerY * 50);
          // remove old tile from vector and replace with new carrot tile
          delete (*backgroundTiles)[playerX * 12 + playerY];
          // sets the current tile player is on to be a carrot tile
          (*backgroundTiles)[playerX * 12 + playerY] = potato;
          break;
        }

        case 8:  // type 8 is carrot seeds in inventory position 8
        {
          // create a new carrot tile (in the heap) with cooridnates of
          // player position and set carrot as a pointer to the carrot tile
          Carrot* carrot = new Carrot(playerX * 50, playerY * 50);
          // remove old tile from vector and replace with new carrot tile
          delete (*backgroundTiles)[playerX * 12 + playerY];
          // sets the current tile player is on to be a carrot tile
          (*backgroundTiles)[playerX * 12 + playerY] = carrot;
          break;
        }

        default:
          std::cout << "error: could not plant as type was invalid" << std::endl;
      };
    }
  }

  // void seedPlant(int seedType, std::vector<tile*>* backgroundTiles) {
  //   int playerX = (floor(body->getPosition().x / 50) * 50);
  //   int playerY = (floor(body->getPosition().y / 50) * 50);

  //   for (int i = 0; i < 144; i++) {
  //     tile* currentTile = (*backgroundTiles)[i];  // Access the current tile
  //                                                 // pointer in the vector

  //     // determine which tile the player is on
  //     if (currentTile->get_x() == playerX &&
  //         currentTile->get_y() == playerY) {
  //       if (currentTile->get_isPlantable() == true) {
  //         switch (seedType) {
  //           case 2:  // type 2 is blueberry seeds in inventory position 2
  //           {
  //             // create a new bluebbery tile (in the heap) with cooridnates
  //             of
  //             // player position and set blueberry as a pointer to the
  //             blueberry
  //             // tile
  //             Blueberry* blueberry = new Blueberry(playerX, playerY);
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
  //             Strawberry* strawberry = new Strawberry(playerX, playerY);
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
  //             tile Potato* potato = new Potato(playerX, playerY);
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
  //             tile Carrot* carrot = new Carrot(playerX, playerY);
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
    int playerX = (floor(body->getPosition().x / 50));
    int playerY = (floor(body->getPosition().y / 50));

    (*backgroundTiles)[playerX * 12 + playerY]->set_hydrationLevel(1);
    return;
  };

  void harvestPlant(std::vector<tile*>* backgroundTiles, Inventory* inventory){

  // Use a map once you have the type of function

    int playerX = (floor(body->getPosition().x / 50));
    int playerY = (floor(body->getPosition().y / 50));

    // Getting yield and inventory position
    int plantYield;
    int plantPos;

    // Setting a constant for easier readability. "currentPlant" just contains an object
    // of the same class as the plant the player is standing on.

    Plant* currentPlant = plantMap[(*backgroundTiles)[playerX * 12 + playerY]->get_className()];

    // Making sure all conditions are met
    if((*backgroundTiles)[playerX * 12 + playerY]->get_className() == "tile"){
      std::cout << "Land cannot be harvested" << std::endl;
      return;
    }
    else if((*backgroundTiles)[playerX * 12 + playerY]->get_growthStage() != currentPlant->get_growTime()){
        std::cout << "Please wait until plant is fully grown" << std::endl;
        return;
    }
    else if((*backgroundTiles)[playerX * 12 + playerY]->get_className() == "Carrot"
      && (inventory->get_inventoryIndex() != 1 || inventory->get_gloveCount() == 0)){
        std::cout << "Must hold gloves to harvest this plant" << std::endl;
        return;
    }
    else if((*backgroundTiles)[playerX * 12 + playerY]->get_className() == "Potato" &&
      (inventory->get_inventoryIndex() != 0 || inventory->get_shovelCount() == 0)){
        std::cout << "Must hold a shovel to harvest this plant" << std::endl;
        return;
    }

    
    
    // Getting yield and inventory position

    plantYield = plantMap[(*backgroundTiles)[playerX * 12 + playerY]->get_className()]->harvestYield();
    plantPos = plantLocationMap[(*backgroundTiles)[playerX * 12 + playerY]->get_className()];

    // Adding plants to the Inventory

    std::cout << plantYield << std::endl;

    inventory->set_fromPos(plantPos, inventory->get_fromPos(plantPos) + plantYield);

    // resetting position as a tile

    delete (*backgroundTiles)[playerX * 12 + playerY];

    (*backgroundTiles)[playerX * 12 + playerY] = new tile(playerX * 50,playerY * 50);

  }



  // movement of the player
  void moveRight() { 
    if(body->getPosition().x < 590){
      body->move(speed, 0); 
    }
  }
  void moveLeft() {
    if(body->getPosition().x > 0){
      body->move(-speed, 0);
    }
  }
  void moveUp() {
    if(body->getPosition().y > 0){
      body->move(0, -speed);
    }
  }
  void moveDown() {
    if(body->getPosition().y < 590){
      body->move(0, speed);
    }
  }

  // getters and setters
  // std::vector<int> get_inventory() { return inventory->get_inventory(); }
  int get_x() { return body->getPosition().x; }
  int get_y() { return body->getPosition().y; }

  void add80shells() { shells += 80; }
  void add100shells() { shells += 100; }
  void add120shells() { shells += 120; }
  void add200shells() { shells += 200; }

  void subtract50shells() { shells -= 50; }
  void subtract70shells() { shells -= 70; }
  void subtract400shells() { shells -= 400; }
  void subtract150shells() { shells -= 150; }

  int get_shells() { return shells; }
  void set_shells(int shellNo) { shells = shellNo; }
};

#endif