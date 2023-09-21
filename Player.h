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

  // accessing plant inventory

  // movement of the player
  void move_right() { body->move(speed, 0); }
  void move_left() { body->move(-speed, 0); }
  void move_up() { body->move(0, -speed); }
  void move_down() { body->move(0, speed); }
};

#endif