#ifndef BUYMENU_H
#define BUYMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class BuyMenu {
 protected:
  RectangleShape* background;
  Text title;
  Font font;
  int length, width;
  bool turnOn;
  int x, y;
  vector<Text> plant_list;
  vector<Text> equipment_list;

 public:
  BuyMenu(int len, int wid) {
    x = 25;
    y = 25;
    length = len;
    width = wid;

    // creating background
    background = new RectangleShape(Vector2f(length, width));
    background->setFillColor(Color::Red);

    // loading font
    font.loadFromFile("textures/font_texture/TTF/dogica.ttf");
    if (!font.loadFromFile("textures/font_texture/TTF/dogica.ttf")) {
      std::cout << "error loading font" << std::endl;  // error testing
    }

    // setting title text
    title.setFont(font);
    title.setString("Buy:");
    title.setCharacterSize(20);
    title.setFillColor(Color::Black);
    title.setPosition(x, y);
    background->setPosition(x, y);

    // setting buying items
    plant_list = {"Carrot"};

    // turning on and off
    turnOn = false;
  }

  // move up and down values in menu items

  // draw function
  void draw(RenderWindow* win) {
    win->draw(*background);
    win->draw(title);
  }

  // setters and getters
  void set_visibility(bool visible) { turnOn = visible; }
  bool get_visibility() { return turnOn; }

  ~BuyMenu() {}
};

#endif