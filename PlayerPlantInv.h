#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Plant.h"

class Player {
 private:
  std::string name;
  CircleShape* body;
  int x, y;
  float speed;
  // inventory for plants
  int plantCount;
  std::vector<Plant*> plantInventory;
  // inventory for equipment

 public:
  Player(int r, int _x, int _y) {
    body = new CircleShape();
    x = _x;
    y = _y;
    speed = 0.1;
    // making plant inventory size
    plantCount = 0;

    body->setRadius(r);
    body->setFillColor(Color::Blue);
    body->setOrigin(r / 2, r / 2);
    body->setPosition(x, y);
  }
  void draw(RenderWindow* win) { win->draw(*body); }

  void addPlant(Plant* plant) {
    if (plantInventory.size() < 10) {
      plantInventory.push_back(plant);
    } else {
      std::cout << "Inventory is full. Cannot add more plants." << std::endl;
    }
  }

  // movement of the player
  void moveRight() { body->move(speed, 0); }
  void moveLeft() { body->move(-speed, 0); }
  void moveUp() { body->move(0, -speed); }
  void moveDown() { body->move(0, speed); }

  // getters and setters
  int get_plantCount() { return plantCount; }
  // accessing plant inventory
  std::vector<Plant*>& get_plantInventory() { return plantInventory; }
};

#endif