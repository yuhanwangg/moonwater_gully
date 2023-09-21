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
  int plant_count;
  std::vector<Plant*> plant_inventory;
  // inventory for equipment

 public:
  Player(int r, int _x, int _y) {
    body = new CircleShape();
    x = _x;
    y = _y;
    speed = 0.1;
    // making plant inventory size
    plant_count = 0;

    body->setRadius(r);
    body->setFillColor(Color::Blue);
    body->setOrigin(r / 2, r / 2);
    body->setPosition(x, y);
  }
  void draw(RenderWindow* win) { win->draw(*body); }

  void add_plant(Plant* plant) {
    if (plant_inventory.size() < 10) {
      plant_inventory.push_back(plant);
    } else {
      std::cout << "Inventory is full. Cannot add more plants." << std::endl;
    }
  }

  // movement of the player
  void move_right() { body->move(speed, 0); }
  void move_left() { body->move(-speed, 0); }
  void move_up() { body->move(0, -speed); }
  void move_down() { body->move(0, speed); }

  // getters and setters
  int get_plant_count() { return plant_count; }
  // accessing plant inventory
  std::vector<Plant*>& get_plant_inventory() { return plant_inventory; }
};

#endif