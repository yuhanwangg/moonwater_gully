#ifndef INVENTORY_H
#define INVENTORY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;

class Inventory {
 protected:
  std::vector<int> inventory;
  int size;

 public:
  Inventory(int size) {
    inventory[0] = 0;  // number of shovels
    inventory[1] = 0;  // number of gloves
    inventory[2] = 0;  // number of blueberry seeds
    inventory[3] = 0;  // number of blueberries
    inventory[4] = 0;  // number of strawberry seeds
    inventory[5] = 0;  // number of strawberries
    inventory[6] = 0;  // number of potato seeds
    inventory[7] = 0;  // number of potatos
    inventory[8] = 0;  // number of carrot seeds
    inventory[9] = 0;  // number of carrots
    this->size = size;
  }

  void scrollInventory() {}

  // getters and setters
  vector<int*> get_inventory() { return inventory; }

  ~Inventory() { delete[] inventory; }
};

#endif