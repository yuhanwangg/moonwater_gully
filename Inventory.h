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
  Text inventory_name[10];
  Texture inventory_images;
  int inventory_index;

 public:
  Inventory(int len, int wid) {
    x = 25;
    y = 500;
    length = len;  // 550
    width = wid;   // 50
    hotBar = new RectangleShape(Vector2f(length, width));
    hotBar->setFillColor(Color::Red);
    hotBar->setPosition(x, y);
    inventory_size = 10;
    inventory_index = 0;

    // loading font
    font.loadFromFile("textures/font_texture/TTF/dogica.ttf");
    if (!font.loadFromFile("textures/font_texture/TTF/dogica.ttf")) {
      std::cout << "error loading font" << std::endl;  // error testing
    }

    inventory_name[0].setFont(font);
    inventory_name[0].setString("shovel");
    inventory_name[0].setCharacterSize(10);
    inventory_name[0].setFillColor(Color::White);
    inventory_name[0].setPosition(30, y + 10);

    inventory_name[1].setFont(font);
    inventory_name[1].setString("glove");
    inventory_name[1].setCharacterSize(10);
    inventory_name[1].setFillColor(Color::White);
    inventory_name[1].setPosition(75, y + 10);

    inventory_name[2].setFont(font);
    inventory_name[2].setString("blueberry seeds");
    inventory_name[2].setCharacterSize(10);
    inventory_name[2].setFillColor(Color::White);
    inventory_name[2].setPosition(125, y + 10);

    inventory_name[3].setFont(font);
    inventory_name[3].setString("blueberries");
    inventory_name[3].setCharacterSize(10);
    inventory_name[3].setFillColor(Color::White);
    inventory_name[3].setPosition(175, y + 10);

    inventory_name[4].setFont(font);
    inventory_name[4].setString("strawberry seeds");
    inventory_name[4].setCharacterSize(10);
    inventory_name[4].setFillColor(Color::White);
    inventory_name[4].setPosition(225, y + 10);

    inventory_name[5].setFont(font);
    inventory_name[5].setString("strawberries");
    inventory_name[5].setCharacterSize(10);
    inventory_name[5].setFillColor(Color::White);
    inventory_name[5].setPosition(275, y + 10);

    inventory_name[6].setFont(font);
    inventory_name[6].setString("potato seeds");
    inventory_name[6].setCharacterSize(10);
    inventory_name[6].setFillColor(Color::White);
    inventory_name[6].setPosition(325, y + 10);

    inventory_name[7].setFont(font);
    inventory_name[7].setString("potato");
    inventory_name[7].setCharacterSize(10);
    inventory_name[7].setFillColor(Color::White);
    inventory_name[7].setPosition(375, y + 10);

    inventory_name[8].setFont(font);
    inventory_name[8].setString("carrot seeds");
    inventory_name[8].setCharacterSize(10);
    inventory_name[8].setFillColor(Color::White);
    inventory_name[8].setPosition(425, y + 10);

    inventory_name[9].setFont(font);
    inventory_name[9].setString("carrot");
    inventory_name[9].setCharacterSize(10);
    inventory_name[9].setFillColor(Color::White);
    inventory_name[9].setPosition(475, y + 10);

    inventory = std::vector<int>(inventory_size, 0);

    inventory_name[inventory_index].setFillColor(Color::Green);
  }

  void scrollInventory() {
    // using space bar
    if (inventory_index + 1 <= inventory_size) {
      inventory_name[inventory_index].setFillColor(Color::White);
      // iterating through array
      inventory_index++;
      if (inventory_index >= inventory_size) {
        inventory_index = 0;
      }

      if (inventory_index == 0) {
        inventory_name[inventory_index].setFillColor(Color::Green);
      }
      inventory_name[inventory_index].setFillColor(Color::Green);
    }
  }

  void drawInventory(RenderWindow* win) {
    win->draw(*hotBar);
    for (int i = 0; i < 9; i++) {
      win->draw(inventory_name[i]);
    }
  }

  // getters and setters
  std::vector<int> get_inventory() { return inventory; }
  int get_inventoryIndex() { return inventory_index; }

  //   ~Inventory() { delete[] inventory; }
};

#endif