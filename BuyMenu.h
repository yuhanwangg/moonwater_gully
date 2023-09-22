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
  std::vector<Text> plant_list;
  int selected_option;
  //   vector<Text> equipment_list;

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
    title.setPosition(x + 10, y + 5);

    // setting buying items text
    plant_list.push_back(Text());
    plant_list[0].setFont(font);
    plant_list[0].setString("carrot seed");
    plant_list[0].setCharacterSize(10);
    plant_list[0].setFillColor(Color::White);
    plant_list[0].setPosition(x + 10, 60);

    plant_list.push_back(Text());
    plant_list[1].setFont(font);
    plant_list[1].setString("potato seed");
    plant_list[1].setCharacterSize(10);
    plant_list[1].setFillColor(Color::White);
    plant_list[1].setPosition(x + 10, 80);

    plant_list.push_back(Text());
    plant_list[2].setFont(font);
    plant_list[2].setString("strawberry seed");
    plant_list[2].setCharacterSize(10);
    plant_list[2].setFillColor(Color::White);
    plant_list[2].setPosition(x + 10, 100);

    plant_list.push_back(Text());
    plant_list[3].setFont(font);
    plant_list[3].setString("blueberry seed");
    plant_list[3].setCharacterSize(10);
    plant_list[3].setFillColor(Color::White);
    plant_list[3].setPosition(x + 10, 120);

    selected_option = -1;

    background->setPosition(x, y);
    // turning on and off
    turnOn = false;
  }

  // move up and down values in menu items
  void MoveUp() {
    if (selected_option - 1 >= 0) {
    }
  }

  // draw function
  void draw(RenderWindow* win) {
    win->draw(*background);
    win->draw(title);
    for (int i = 0; i < 4; i++) {
      win->draw(plant_list[i]);
    }
  }

  // setters and getters
  void set_visibility(bool visible) { turnOn = visible; }
  bool get_visibility() { return turnOn; }

  ~BuyMenu() {}
};

#endif