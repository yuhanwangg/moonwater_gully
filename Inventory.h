#ifndef INVENTORY_H
#define INVENTORY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;

class Inventory {
 protected:
  std::vector<int> inventory;
  RectangleShape* hotBar;
  int length, width;
  int x, y;
  int inventory_size;
  Font font;
  Text inventory_name[3];
  int inventory_count;

 public:
  Inventory(int len, int wid) {
    x = 25;
    y = 500;
    length = len;  // 500
    width = wid;   // 20
    hotBar = new RectangleShape(Vector2f(length, width));
    hotBar->setFillColor(Color::Red);
    hotBar->setPosition(x, y);
    inventory_size = 10;

    // loading font
    font.loadFromFile("textures/font_texture/TTF/dogica.ttf");
    if (!font.loadFromFile("textures/font_texture/TTF/dogica.ttf")) {
      std::cout << "error loading font" << std::endl;  // error testing
    }

    inventory_name[0].setFont(font);
    inventory_name[0].setString("shovel");
    inventory_name[0].setCharacterSize(10);
    inventory_name[0].setFillColor(Color::White);
    inventory_name[0].setPosition(x + 10, y + 10);

    inventory_name[1].setFont(font);
    inventory_name[1].setString("glove");
    inventory_name[1].setCharacterSize(10);
    inventory_name[1].setFillColor(Color::White);
    inventory_name[1].setPosition(x + 100, y + 10);

    inventory_name[2].setFont(font);
    inventory_name[2].setString("blueberry seeds");
    inventory_name[2].setCharacterSize(10);
    inventory_name[2].setFillColor(Color::White);
    inventory_name[2].setPosition(x + 200, y + 10);

    inventory = std::vector<int>(inventory_size, 0);

    // inventory[0] = 0;  // number of shovels
    // inventory[1] = 0;  // number of gloves
    // inventory[2] = 0;  // number of blueberry seeds
    // inventory[3] = 0;  // number of blueberries
    // inventory[4] = 0;  // number of strawberry seeds
    // inventory[5] = 0;  // number of strawberries
    // inventory[6] = 0;  // number of potato seeds
    // inventory[7] = 0;  // number of potatos
    // inventory[8] = 0;  // number of carrot seeds
    // inventory[9] = 0;  // number of carrots
  }

  void scrollInventory() {
    // using space bar
    if (inventory_count + 1 <= inventory_size) {
    }
  }

  void drawInventory(RenderWindow* win) {
    win->draw(*hotBar);
    for (int i = 0; i < 3; i++) {
      win->draw(inventory_name[i]);
    }
  }

  // getters and setters
  std::vector<int> get_inventory() { return inventory; }

  //   ~Inventory() { delete[] inventory; }
};

#endif