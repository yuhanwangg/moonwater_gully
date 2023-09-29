#ifndef BUYMENU_H
#define BUYMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.h"
#include "Player.h"
using namespace sf;

class BuyMenu : public Menu {
 protected:
  RectangleShape* buy_background;
  RectangleShape* purchase_box;
  bool buyOn;
  Text catalogue[6];
  Text title_buy;
  Text purchase[3];  // successfull purchase or not
  int buy_select;

  bool success_check;
  bool failure_check;

 public:
  BuyMenu(int len, int wid) : Menu(len, wid) {
    x = 25;
    y = 25;
    length = len;  // 250
    width = wid;   // 400
    max_option = 6;

    success_check = false;
    failure_check = false;

    // creating background
    buy_background = new RectangleShape(Vector2f(length, width));
    buy_background->setFillColor(Color::Red);

    purchase_box = new RectangleShape(Vector2f(200, 100));
    purchase_box->setFillColor(Color::Blue);

    // setting buying items text
    int text_x = 35;
    catalogue[0].setFont(font);
    catalogue[0].setString("1x carrot seed       50");
    catalogue[0].setCharacterSize(10);
    catalogue[0].setFillColor(Color::White);
    catalogue[0].setPosition(text_x, 70);

    catalogue[1].setFont(font);
    catalogue[1].setString("1x potato seed       50");
    catalogue[1].setCharacterSize(10);
    catalogue[1].setFillColor(Color::White);
    catalogue[1].setPosition(text_x, 90);

    catalogue[2].setFont(font);
    catalogue[2].setString("1x strawberry seed   70");
    catalogue[2].setCharacterSize(10);
    catalogue[2].setFillColor(Color::White);
    catalogue[2].setPosition(text_x, 110);

    catalogue[3].setFont(font);
    catalogue[3].setString("1x blueberry seed    70");
    catalogue[3].setCharacterSize(10);
    catalogue[3].setFillColor(Color::White);
    catalogue[3].setPosition(text_x, 130);

    catalogue[4].setFont(font);
    catalogue[4].setString("1x shovel           300");
    catalogue[4].setCharacterSize(10);
    catalogue[4].setFillColor(Color::White);
    catalogue[4].setPosition(text_x, 180);

    catalogue[5].setFont(font);
    catalogue[5].setString("1x gloves           150");
    catalogue[5].setCharacterSize(10);
    catalogue[5].setFillColor(Color::White);
    catalogue[5].setPosition(text_x, 200);

    buy_select = 0;

    catalogue[buy_select].setFillColor(Color::Yellow);

    // creating purchase box list:
    purchase[0].setFont(font);
    purchase[0].setString("purchase item?");
    purchase[0].setCharacterSize(10);
    purchase[0].setFillColor(Color::White);
    purchase[0].setPosition(290, 35);

    purchase[1].setFont(font);
    purchase[1].setString("insufficient funds!");
    purchase[1].setCharacterSize(10);
    purchase[1].setFillColor(Color::White);
    purchase[1].setPosition(310, 50);

    purchase[2].setFont(font);
    purchase[2].setString("purchase success!");
    purchase[2].setCharacterSize(10);
    purchase[2].setFillColor(Color::White);
    purchase[2].setPosition(310, 50);

    buy_background->setPosition(x, y);
    purchase_box->setPosition(280, 25);
    // turning on and off
    buyOn = false;
  }

  // move up and down values in menu items

  void moveDown() {
    // checking array
    if (buy_select + 1 < max_option) {
      // changing text colour
      catalogue[buy_select].setFillColor(sf::Color::White);
      // iterating array
      buy_select++;
      // changing text colour
      catalogue[buy_select].setFillColor(sf::Color::Yellow);
    } else if (buy_select == 5) {
      catalogue[buy_select].setFillColor(sf::Color::Yellow);
    } else {
      buy_select = 0;
      catalogue[buy_select].setFillColor(sf::Color::Yellow);
    }
  }
  void moveUp() {
    // checking array
    if (buy_select - 1 >= 0) {
      catalogue[buy_select].setFillColor(sf::Color::White);
      buy_select--;
      // changing text colour
      catalogue[buy_select].setFillColor(sf::Color::Yellow);
    } else {
      buy_select = 0;
    }
  }

  // draw function
  void draw(RenderWindow* win) {
    win->draw(*buy_background);
    win->draw(*purchase_box);
    win->draw(title_buy);
    win->draw(purchase[0]);
    for (int i = 0; i < max_option; i++) {
      win->draw(catalogue[i]);
    }
  }

  // checker if the player has sufficient funds to purchase good
  bool purchase_status(Player* player, int item_no) {
    switch (item_no) {
      case 0:  // carrot
        if (player->get_shells() >= 50) {
          player->subtract_50shells();
          return true;
        } else {
          return false;
        }
        break;
      case 1:  // potato
        if (player->get_shells() >= 50) {
          return true;
        } else {
          return false;
        }
        break;
      case 2:  // strawberry
        if (player->get_shells() >= 70) {
          return true;
        } else {
          return false;
        }
        break;
      case 3:  // blueberry
        if (player->get_shells() >= 70) {
          return true;
        } else {
          return false;
        }
        break;
      case 4:  // shovel
        if (player->get_shells() >= 400) {
          return true;
        } else {
          return false;
        }
        break;
      case 5:  // gloves
        if (player->get_shells() >= 150) {
          return true;
        } else {
          return false;
        }
        break;
      default:
        return false;
    }
  }

  // drawing success or purchase error
  void draw_purchaseError(RenderWindow* win) { win->draw(purchase[1]); }
  void draw_purchaseSuccess(RenderWindow* win) { win->draw(purchase[2]); }

  // setters and getters
  bool get_successCheck() { return success_check; }
  void set_successCheck(bool su) { success_check = su; }
  bool get_failureCheck() { return failure_check; }
  void set_failureCheck(bool fa) { failure_check = fa; }

  void set_buySelect(int select) { buy_select = select; }
  int get_buySelect() { return buy_select; }

  void set_maxOption(int max) { max_option = max; }
  int get_maxOption() { return max_option; }

  bool get_buyOn() { return buyOn; }
  void set_buyOn(bool visible) { buyOn = visible; }

  ~BuyMenu() {
    delete[] buy_background;
    delete[] purchase_box;
  }
};

#endif