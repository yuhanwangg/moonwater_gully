#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Inventory.h"
#include "Plant.h"
// #include "PlayerInteraction.h"

class Player {
 private:
  std::string name;
  CircleShape* body;
  int x, y;
  float speed;
  int shells;
  // Inventory* inventory = new Inventory(550, 50);

 public:
  Player(int r, int _x, int _y) {
    body = new CircleShape();
    x = _x;
    y = _y;
    shells = 500;
    speed = 0.1;

    body->setRadius(r);
    body->setFillColor(Color::Blue);
    body->setOrigin(r / 2, r / 2);
    body->setPosition(x, y);
  }

  void draw(RenderWindow* win) {
    win->draw(*body);
    // inventory->drawInventory(win);
  }

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