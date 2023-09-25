#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Plant.h"
#include "PlayerInteraction.h"


class Player : public PlayerInteraction {
 private:
  std::string name;
  CircleShape* body;
  int x, y;
  float speed;
  int shells;
  // inventory for plants

  // inventory for equipment

 public:
  Player(int r, int _x, int _y) {
    body = new CircleShape();
    x = _x;
    y = _y;
    shells = 500;
    speed = 0.1;
    // making plant inventory size
    // plant_count = 0;
    body->setRadius(r);
    body->setFillColor(Color::Blue);
    body->setOrigin(r / 2, r / 2);
    body->setPosition(x, y);
  }

  // bool isPlantable(){
  //     // check if the land that player is on is plantable or not
  //     // use the text class to show plantable or not through if statement in
  //     the
  //     // driver
  // };

  void draw(RenderWindow* win) { win->draw(*body); }

  // accessing plant inventory

  // movement of the player
  void move_right() { body->move(speed, 0); }
  void move_left() { body->move(-speed, 0); }
  void move_up() { body->move(0, -speed); }
  void move_down() { body->move(0, speed); }

  // getters and setters
  int get_x() { return body->getPosition().x; }
  int get_y() { return body->getPosition().y; }

  int get_shells() { return shells; }
  void set_shells(int shell_no) { shells = shell_no; }
};

#endif