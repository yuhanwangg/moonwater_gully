#ifndef BUYMENU_H
#define BUYMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Menu.h"
#include "Player.h"
using namespace sf;

class BuyMenu : public Menu {
 protected:
  RectangleShape* buyBackground;
  RectangleShape* purchaseBox;
  bool buyOn;
  Text catalogue[6];
  Text titleBuy;
  Text purchase[3];  // successfull purchase or not
  int buySelect;

  bool successCheck;
  bool failureCheck;

  Texture bgTexture;

 public:
  BuyMenu(int len, int wid) : Menu(len, wid) {
    x = 25;
    y = 25;
    length = len;  // 250
    width = wid;   // 400
    maxOption = 6;

    successCheck = false;
    failureCheck = false;

    // creating background
    buyBackground = new RectangleShape(Vector2f(length, width));
    buyBackground->setFillColor(Color::White);

    purchaseBox = new RectangleShape(Vector2f(230, 100));
    purchaseBox->setFillColor(Color::White);

    bgTexture.loadFromFile("textures/beigeBackground.png");
    buyBackground->setTexture(&bgTexture);
    purchaseBox->setTexture(&bgTexture);

    // setting buying items text
    int textX = 35;
    catalogue[0].setFont(font);
    catalogue[0].setString("1x carrot seed       50");
    catalogue[0].setCharacterSize(10);
    catalogue[0].setFillColor(Color::White);
    catalogue[0].setPosition(textX, 70);

    catalogue[1].setFont(font);
    catalogue[1].setString("1x potato seed       50");
    catalogue[1].setCharacterSize(10);
    catalogue[1].setFillColor(Color::White);
    catalogue[1].setPosition(textX, 90);

    catalogue[2].setFont(font);
    catalogue[2].setString("1x strawberry seed   70");
    catalogue[2].setCharacterSize(10);
    catalogue[2].setFillColor(Color::White);
    catalogue[2].setPosition(textX, 110);

    catalogue[3].setFont(font);
    catalogue[3].setString("1x blueberry seed    70");
    catalogue[3].setCharacterSize(10);
    catalogue[3].setFillColor(Color::White);
    catalogue[3].setPosition(textX, 130);

    catalogue[4].setFont(font);
    catalogue[4].setString("1x shovel           300");
    catalogue[4].setCharacterSize(10);
    catalogue[4].setFillColor(Color::White);
    catalogue[4].setPosition(textX, 180);

    catalogue[5].setFont(font);
    catalogue[5].setString("1x gloves           150");
    catalogue[5].setCharacterSize(10);
    catalogue[5].setFillColor(Color::White);
    catalogue[5].setPosition(textX, 200);

    buySelect = 0;

    catalogue[buySelect].setFillColor(Color::Yellow);

    // creating purchase box list:
    purchase[0].setFont(font);
    purchase[0].setString("purchase item?");
    purchase[0].setCharacterSize(10);
    purchase[0].setFillColor(Color::Black);
    purchase[0].setPosition(290, 35+300);

    purchase[1].setFont(font);
    purchase[1].setString("Insufficient funds!");
    purchase[1].setCharacterSize(10);
    purchase[1].setFillColor(Color::Black);
    purchase[1].setPosition(290, 50+320);

    purchase[2].setFont(font);
    purchase[2].setString("Purchase success!");
    purchase[2].setCharacterSize(10);
    purchase[2].setFillColor(Color::Black);
    purchase[2].setPosition(290, 50+320);

    buyBackground->setPosition(x, y);
    purchaseBox->setPosition(280, 25+300);
    // turning on and off
    buyOn = false;
  }

  // move up and down values in menu items

  void moveDown() {
    // checking array
    if (buySelect + 1 < maxOption) {
      // changing text colour
      catalogue[buySelect].setFillColor(sf::Color::White);
      // iterating array
      buySelect++;
      // changing text colour
      catalogue[buySelect].setFillColor(sf::Color::Yellow);
    } else if (buySelect == 5) {
      catalogue[buySelect].setFillColor(sf::Color::Yellow);
    } else {
      buySelect = 0;
      catalogue[buySelect].setFillColor(sf::Color::Yellow);
    }
  }
  void moveUp() {
    // checking array
    if (buySelect - 1 >= 0) {
      catalogue[buySelect].setFillColor(sf::Color::White);
      buySelect--;
      // changing text colour
      catalogue[buySelect].setFillColor(sf::Color::Yellow);
    } else {
      buySelect = 0;
    }
  }

  // draw function
  void draw(RenderWindow* win) {
    win->draw(*buyBackground);
    win->draw(*purchaseBox);
    win->draw(titleBuy);
    win->draw(purchase[0]);
    for (int i = 0; i < maxOption; i++) {
      win->draw(catalogue[i]);
    }
  }

  // checker if the player has sufficient funds to purchase good
  bool purchaseStatus(Player* player, int itemNo) {
    switch (itemNo) {
      case 0:  // carrot
        if (player->get_shells() >= 50) {
          player->subtract50shells();
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
  void drawPurchaseError(RenderWindow* win) { win->draw(purchase[1]); }
  void drawPurchaseSuccess(RenderWindow* win) { win->draw(purchase[2]); }

  // setters and getters
  bool get_successCheck() { return successCheck; }
  void set_successCheck(bool su) { successCheck = su; }
  bool get_failureCheck() { return failureCheck; }
  void set_failureCheck(bool fa) { failureCheck = fa; }

  void set_buySelect(int select) { buySelect = select; }
  int get_buySelect() { return buySelect; }

  void set_maxOption(int max) { maxOption = max; }
  int get_maxOption() { return maxOption; }

  bool get_buyOn() { return buyOn; }
  void set_buyOn(bool visible) { buyOn = visible; }

  ~BuyMenu() {
    delete[] buyBackground;
    delete[] purchaseBox;
  }
};

#endif