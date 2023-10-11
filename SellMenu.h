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
  RectangleShape* sellBackground;
  RectangleShape* sellBox;
  bool sellOn;  // turning the selling box on
  Text sellCatalogue[4];
  Text sellSuccess[3];  // box displaying
  int sellSelect;       //  selecting the item in the sell menu

  bool successCheck;
  bool failureCheck;

  Texture bgTexture;

 public:
  SellMenu(int len, int wid) : Menu(len, wid) {
    x = 25;
    y = 25;
    length = len;   // 200
    width = wid;    // 300
    maxOption = 4;  // only sell blueberries, strawberries, potatos and carrots

    successCheck = false;
    failureCheck = false;

    // background boxes
    sellBackground = new RectangleShape(Vector2f(length, width));
    sellBackground->setFillColor(Color::White);

    sellBox = new RectangleShape(Vector2f(230, 100));
    sellBox->setFillColor(Color::White);

    // loading in textures:
    bgTexture.loadFromFile("textures/beigeBackground.png");
    sellBackground->setTexture(&bgTexture);
    sellBox->setTexture(&bgTexture);

    // setting the selling menu
    int textX = 35;
    sellCatalogue[0].setFont(font);
    sellCatalogue[0].setString("1x carrot      100");
    sellCatalogue[0].setCharacterSize(10);
    sellCatalogue[0].setFillColor(Color::White);
    sellCatalogue[0].setPosition(textX, 70);

    sellCatalogue[1].setFont(font);
    sellCatalogue[1].setString("1x potato       80");
    sellCatalogue[1].setCharacterSize(10);
    sellCatalogue[1].setFillColor(Color::White);
    sellCatalogue[1].setPosition(textX, 90);

    sellCatalogue[2].setFont(font);
    sellCatalogue[2].setString("1x strawberry   200");
    sellCatalogue[2].setCharacterSize(10);
    sellCatalogue[2].setFillColor(Color::White);
    sellCatalogue[2].setPosition(textX, 110);

    sellCatalogue[3].setFont(font);
    sellCatalogue[3].setString("1x blueberry    120");
    sellCatalogue[3].setCharacterSize(10);
    sellCatalogue[3].setFillColor(Color::White);
    sellCatalogue[3].setPosition(textX, 130);

    // creating purchase box list:
    sellSuccess[0].setFont(font);
    sellSuccess[0].setString("sell item?");
    sellSuccess[0].setCharacterSize(10);
    sellSuccess[0].setFillColor(Color::Black);
    sellSuccess[0].setPosition(290, 35 + 200);

    sellSuccess[1].setFont(font);
    sellSuccess[1].setString("sold!");
    sellSuccess[1].setCharacterSize(10);
    sellSuccess[1].setFillColor(Color::White);
    sellSuccess[1].setPosition(310, 50);

    sellSuccess[2].setFont(font);
    sellSuccess[2].setString("you don't have any of this item to sell!");
    sellSuccess[2].setCharacterSize(10);
    sellSuccess[2].setFillColor(Color::White);
    sellSuccess[2].setPosition(310, 50 + 200);

    sellBackground->setPosition(x, y);
    sellBox->setPosition(280, 25 + 200);
    // turning on and off
    sellOn = false;
  }
  void moveDown() {
    // checking array
    if (sellSelect + 1 < maxOption) {
      // changing text colour
      sellCatalogue[sellSelect].setFillColor(sf::Color::White);
      // iterating array
      sellSelect++;
      // changing text colour
      sellCatalogue[sellSelect].setFillColor(sf::Color::Yellow);
    } else if (sellSelect == 3) {
      sellCatalogue[sellSelect].setFillColor(sf::Color::Yellow);
    } else {
      sellSelect = 0;
      sellCatalogue[sellSelect].setFillColor(sf::Color::Yellow);
    }
  }
  void moveUp() {
    // checking array
    if (sellSelect - 1 >= 0 && sellSelect < maxOption) {
      sellCatalogue[sellSelect].setFillColor(sf::Color::White);
      sellSelect--;
      // changing text colour
      sellCatalogue[sellSelect].setFillColor(sf::Color::Yellow);
    } else if (sellSelect == 0) {
      sellCatalogue[sellSelect].setFillColor(sf::Color::Yellow);
    } else {
      sellSelect = 0;
      sellCatalogue[sellSelect].setFillColor(sf::Color::Yellow);
    }
  }

  bool purchaseStatus(Inventory* inventory, int itemNo) {
    switch (itemNo) {
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
    win->draw(*sellBackground);
    win->draw(*sellBox);
    for (int i = 0; i < maxOption; i++) {
      win->draw(sellCatalogue[i]);
    }
    win->draw(sellSuccess[0]);
  }

  void drawSellSuccess(RenderWindow* win) { win->draw(sellSuccess[1]); }
  void drawSellFailure(RenderWindow* win) { win->draw(sellSuccess[2]); };

  // setters and getters
  bool get_successCheck() { return successCheck; }
  void set_successCheck(bool su) { successCheck = su; }
  bool get_failureCheck() { return failureCheck; }
  void set_failureCheck(bool fa) { failureCheck = fa; }

  void set_sellSelect(int select) { sellSelect = select; }
  int get_sellSelect() { return sellSelect; }

  void set_maxOption(int max) { maxOption = max; }
  int get_maxOption() { return maxOption; }

  bool get_sellOn() { return sellOn; }
  void set_sellOn(bool visible) { sellOn = visible; }

  ~SellMenu() {
    delete[] sellBackground;
    delete[] sellBox;
  }
};

#endif
