#ifndef SELLMENU_H
#define SELLMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Inventory.h"
#include "Menu.h"
#include "Player.h"
using namespace sf;

class SellMenu : public Menu {
 protected:
  RectangleShape* sell_background;
  RectangleShape* sell_box;
  bool sellOn;  // turning the selling box on
  Text sell_catalogue[4];
  Text sell_success[3];  // box displaying
  int sell_select;       //  selecting the item in the sell menu

  bool success_check;
  bool failure_check;

  Texture bg_texture;

 public:
  SellMenu(int len, int wid) : Menu(len, wid) {
    x = 25;
    y = 25;
    length = len;    // 200
    width = wid;     // 300
    max_option = 4;  // only sell blueberries, strawberries, potatos and carrots

    success_check = false;
    failure_check = false;

    // background boxes
    sell_background = new RectangleShape(Vector2f(length, width));
    sell_background->setFillColor(Color::White);

    sell_box = new RectangleShape(Vector2f(230, 100));
    sell_box->setFillColor(Color::White);

    // loading in textures:
    bg_texture.loadFromFile("textures/beigeBackground.png");
    sell_background->setTexture(&bg_texture);
    sell_box->setTexture(&bg_texture);

    // setting the selling menu
    int text_x = 35;
    sell_catalogue[0].setFont(font);
    sell_catalogue[0].setString("1x carrot      100");
    sell_catalogue[0].setCharacterSize(10);
    sell_catalogue[0].setFillColor(Color::White);
    sell_catalogue[0].setPosition(text_x, 70);

    sell_catalogue[1].setFont(font);
    sell_catalogue[1].setString("1x potato       80");
    sell_catalogue[1].setCharacterSize(10);
    sell_catalogue[1].setFillColor(Color::White);
    sell_catalogue[1].setPosition(text_x, 90);

    sell_catalogue[2].setFont(font);
    sell_catalogue[2].setString("1x strawberry   200");
    sell_catalogue[2].setCharacterSize(10);
    sell_catalogue[2].setFillColor(Color::White);
    sell_catalogue[2].setPosition(text_x, 110);

    sell_catalogue[3].setFont(font);
    sell_catalogue[3].setString("1x blueberry    120");
    sell_catalogue[3].setCharacterSize(10);
    sell_catalogue[3].setFillColor(Color::White);
    sell_catalogue[3].setPosition(text_x, 130);

    // creating purchase box list:
    sell_success[0].setFont(font);
    sell_success[0].setString("sell item?");
    sell_success[0].setCharacterSize(10);
    sell_success[0].setFillColor(Color::Black);
    sell_success[0].setPosition(290, 35 + 200);

    sell_success[1].setFont(font);
    sell_success[1].setString("sold!");
    sell_success[1].setCharacterSize(10);
    sell_success[1].setFillColor(Color::White);
    sell_success[1].setPosition(310, 50);

    sell_success[2].setFont(font);
    sell_success[2].setString("you don't have any of this item to sell!");
    sell_success[2].setCharacterSize(10);
    sell_success[2].setFillColor(Color::White);
    sell_success[2].setPosition(310, 50 + 200);

    sell_background->setPosition(x, y);
    sell_box->setPosition(280, 25 + 200);
    // turning on and off
    sellOn = false;
  }
  void moveDown() {
    // checking array
    if (sell_select + 1 < max_option) {
      // changing text colour
      sell_catalogue[sell_select].setFillColor(sf::Color::White);
      // iterating array
      sell_select++;
      // changing text colour
      sell_catalogue[sell_select].setFillColor(sf::Color::Yellow);
    } else if (sell_select == 3) {
      sell_catalogue[sell_select].setFillColor(sf::Color::Yellow);
    } else {
      sell_select = 0;
      sell_catalogue[sell_select].setFillColor(sf::Color::Yellow);
    }
  }
  void moveUp() {
    // checking array
    if (sell_select - 1 >= 0 && sell_select < max_option) {
      sell_catalogue[sell_select].setFillColor(sf::Color::White);
      sell_select--;
      // changing text colour
      sell_catalogue[sell_select].setFillColor(sf::Color::Yellow);
    } else if (sell_select == 0) {
      sell_catalogue[sell_select].setFillColor(sf::Color::Yellow);
    } else {
      sell_select = 0;
      sell_catalogue[sell_select].setFillColor(sf::Color::Yellow);
    }
  }

  bool purchase_status(Inventory* inventory, int item_no) {
    switch (item_no) {
      case 0:  // carrot
        if (inventory->get_carrotCount() >= 1) {
          return true;
        } else {
          return false;
        }
        break;
      case 1:  // potato
        if (inventory->get_potatoCount() >= 1) {
          return true;
        } else {
          return false;
        }
        break;
      case 2:  // strawberry
        if (inventory->get_strawberryCount() >= 1) {
          return true;
        } else {
          return false;
        }
        break;
      case 3:  // blueberry
        if (inventory->get_blueberryCount() >= 1) {
          return true;
        } else {
          return false;
        }
        break;
      default:
        return false;
    }
  }
  void draw(RenderWindow* win) {
    win->draw(*sell_background);
    win->draw(*sell_box);
    for (int i = 0; i < max_option; i++) {
      win->draw(sell_catalogue[i]);
    }
    win->draw(sell_success[0]);
  }

  void draw_sellSuccess(RenderWindow* win) { win->draw(sell_success[1]); }
  void draw_sellFailure(RenderWindow* win) { win->draw(sell_success[2]); };

  // setters and getters
  bool get_successCheck() { return success_check; }
  void set_successCheck(bool su) { success_check = su; }
  bool get_failureCheck() { return failure_check; }
  void set_failureCheck(bool fa) { failure_check = fa; }

  void set_sellSelect(int select) { sell_select = select; }
  int get_sellSelect() { return sell_select; }

  void set_maxOption(int max) { max_option = max; }
  int get_maxOption() { return max_option; }

  bool get_sellOn() { return sellOn; }
  void set_sellOn(bool visible) { sellOn = visible; }

  ~SellMenu() {
    delete[] sell_background;
    delete[] sell_box;
  }
};

#endif
