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

    inventory = std::vector<int>(inventory_size,
                                 0);  // initialising inventory values as 0

    inventory_name[inventory_index].setFillColor(Color::Green);
  }

  void scrollInventory() {
    // using space bar
    if (inventory_index + 1 <= inventory_size) {
      inventory_name[inventory_index].setFillColor(Color::White);
      // iterating through array
      inventory_index++;
      if (inventory_index >= inventory_size - 1) {
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
  void set_inventoryIndex(int ind) { inventory_index = ind; }

  int get_shovelCount() { return inventory[0]; }
  int get_gloveCount() { return inventory[1]; }
  int get_blueberrySeedsCount() { return inventory[2]; }
  int get_blueberryCount() { return inventory[3]; }
  int get_strawberrySeedsCount() { return inventory[4]; }
  int get_strawberryCount() { return inventory[5]; }
  int get_potatoSeedsCount() { return inventory[6]; }
  int get_potatoCount() { return inventory[7]; }
  int get_carrotSeedsCount() { return inventory[8]; }
  int get_carrotCount() { return inventory[9]; }

  void set_shovelCount(int shovel) { inventory[0] = shovel; }
  void set_gloveCount(int glove) { inventory[1] = glove; }
  void set_blueberrySeedsCount(int blue_seeds) { inventory[2] = blue_seeds; }
  void set_blueberryCount(int blue) { inventory[3] = blue; }
  void set_strawberrySeedsCount(int straw_seeds) { inventory[4] = straw_seeds; }
  void set_strawberryCount(int straw) { inventory[5] = straw; }
  void set_potatoSeedsCount(int potato_seed) { inventory[6] = potato_seed; }
  void set_potatoCount(int potato) { inventory[7] = potato; }
  void set_carrotSeedsCount(int carrot_seed) { inventory[8] = carrot_seed; }
  void set_carrotCount(int carrot) { inventory[9] = carrot; }

  void add_shovelCount() { inventory[0] += 1; }
  void add_gloveCount() { inventory[1] += 1; }
  void add_blueberrySeedsCount() { inventory[2] += 1; }
  void add_blueberryCount() { inventory[3] += 1; }
  void add_strawberrySeedsCount() { inventory[4] += 1; }
  void add_strawberryCount() { inventory[5] += 1; }
  void add_potatoSeedsCount() { inventory[6] += 1; }
  void add_potatoCount() { inventory[7] += 1; }
  void add_carrotSeedsCount() { inventory[8] += 1; }
  void add_carrotCount() { inventory[9] += 1; }

  void subtract_shovelCount() { inventory[0] -= 1; }
  void subtract_gloveCount() { inventory[1] -= 1; }
  void subtract_blueberrySeedsCount() { inventory[2] -= 1; }
  void subtract_blueberryCount() { inventory[3] -= 1; }
  void subtract_strawberrySeedsCount() { inventory[4] -= 1; }
  void subtract_strawberryCount() { inventory[5] -= 1; }
  void subtract_potatoSeedsCount() { inventory[6] -= 1; }
  void subtract_potatoCount() { inventory[7] -= 1; }
  void subtract_carrotSeedsCount() { inventory[8] -= 1; }
  void subtract_carrotCount() { inventory[9] -= 1; }

  //   ~Inventory() { delete[] inventory; }
};

#endif