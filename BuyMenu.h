#ifndef BUYMENU_H
#define BUYMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.h"
using namespace sf;

class BuyMenu : public Menu {
 protected:
  RectangleShape* buy_background;
  bool buyOn;
  Text plant_list[4];
  Text title_buy;

 public:
  BuyMenu(int len, int wid) : Menu(len, wid) {
    x = 25;
    y = 25;
    length = len;
    width = wid;
    selected_option = 0;
    max_option = 4;

    // creating background
    buy_background = new RectangleShape(Vector2f(length, width));
    buy_background->setFillColor(Color::Red);

    // setting title text
    title_buy.setFont(font);
    title_buy.setString("Buy:");
    title_buy.setCharacterSize(20);
    title_buy.setFillColor(Color::Black);
    title_buy.setPosition(x + 10, y + 5);

    // setting buying items text
    plant_list[0].setFont(font);
    plant_list[0].setString("carrot seed");
    plant_list[0].setCharacterSize(10);
    plant_list[0].setFillColor(Color::White);
    plant_list[0].setPosition(x + 10, 60);

    plant_list[1].setFont(font);
    plant_list[1].setString("potato seed");
    plant_list[1].setCharacterSize(10);
    plant_list[1].setFillColor(Color::White);
    plant_list[1].setPosition(x + 10, 80);

    plant_list[2].setFont(font);
    plant_list[2].setString("strawberry seed");
    plant_list[2].setCharacterSize(10);
    plant_list[2].setFillColor(Color::White);
    plant_list[2].setPosition(x + 10, 100);

    plant_list[3].setFont(font);
    plant_list[3].setString("blueberry seed");
    plant_list[3].setCharacterSize(10);
    plant_list[3].setFillColor(Color::White);
    plant_list[3].setPosition(x + 10, 120);

    selected_option = 0;

    plant_list[selected_option].setFillColor(Color::Yellow);

    buy_background->setPosition(x, y);
    // turning on and off
    buyOn = false;
  }

  // move up and down values in menu items

  void moveDown() {
    // checking array
    if (selected_option + 1 <= max_option) {
      // changing text colour
      plant_list[selected_option].setFillColor(sf::Color::White);
      // iterating array
      selected_option++;
      // changing text colour
      plant_list[selected_option].setFillColor(sf::Color::Yellow);
    } else {
      selected_option = 0;
    }
  }
  void moveUp() {
    // checking array
    if (selected_option - 1 >= 0) {
      plant_list[selected_option].setFillColor(sf::Color::White);
      selected_option--;
      // changing text colour
      plant_list[selected_option].setFillColor(sf::Color::Yellow);
    } else {
      selected_option = 0;
    }
  }

  // draw function
  void draw(RenderWindow* win) {
    win->draw(*buy_background);
    win->draw(title_buy);
    for (int i = 0; i < 4; i++) {
      win->draw(plant_list[i]);
    }
  }

  // setters and getters
  bool get_buyOn() { return buyOn; }
  void set_buyOn(bool visible) { buyOn = visible; }

  ~BuyMenu() {}
};

#endif