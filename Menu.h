#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "Player.h"
using namespace sf;

class Menu {
 protected:
  // rectangle shape for menu size
  RectangleShape* background;
  RectangleShape* howToPlayBg;
  RectangleShape* controlBg;
  RectangleShape* saveBg;

  Texture bgTexture;
  Texture howToPlayTexture;
  Texture controlTexture;

  bool howToPlayVisible;
  bool controlVisible;
  bool saveVisible;
  bool isMainMenuOpen;
  bool walletVisibility;
  Font font;
  Text title;
  Text wallet;

  std::string walletNumber;

  int x, y;
  int selectedOption;
  int length, width;
  int maxOption;
  Text menu[4];
  bool turnOn;

  // The text information for each window
  Text howToPlayText;
  Text controlText;

 public:
  Menu(int len, int wid) {
    length = len;
    width = wid;
    x = 25;
    y = 25;
    maxOption = 4;
    turnOn = true;

    howToPlayVisible = false;
    controlVisible = false;
    saveVisible = false;
    isMainMenuOpen = false;
    walletVisibility = false;

    // creating background — maybe change into another function
    background = new RectangleShape(Vector2f(360, 150));
    background->setPosition(x - 5, y);

    // how to play image
    howToPlayBg = new RectangleShape(Vector2f(550, 500));
    howToPlayBg->setFillColor(Color::White);
    howToPlayBg->setPosition(x, 80);

    // controls image
    controlBg = new RectangleShape(Vector2f(330, 400));
    controlBg->setFillColor(Color::White);
    controlBg->setPosition(245, 85);

    saveBg = new RectangleShape(Vector2f(length, width));
    saveBg->setPosition(150, 150);

    // loading in textures:
    bgTexture.loadFromFile("textures/main_menu.png");
    howToPlayTexture.loadFromFile("textures/beigeBackground.png");
    controlTexture.loadFromFile("textures/beigeBackground.png");
    background->setTexture(&bgTexture);
    howToPlayBg->setTexture(&howToPlayTexture);
    controlBg->setTexture(&controlTexture);
    saveBg->setTexture(&bgTexture);
    background->setTextureRect(IntRect(0, 0, len, wid));
    howToPlayBg->setTextureRect(IntRect(0, 0, 550, 500));
    controlBg->setTextureRect(IntRect(0, 0, 330, 400));
    saveBg->setTextureRect(IntRect(0, 0, len, wid));

    // loading font
    font.loadFromFile("textures/font_texture/TTF/dogica.ttf");
    if (!font.loadFromFile("textures/font_texture/TTF/dogica.ttf")) {
      std::cout << "error loading font" << std::endl;  // error testing
    }

    // buidling the title text
    title.setFont(font);
    title.setString("Moonwater Gully");
    title.setCharacterSize(20);
    title.setFillColor(Color::Black);
    title.setPosition(x + 15, y + 15);

    // building options for menu

    // play button — closes menu and let's you play
    menu[0].setFont(font);
    menu[0].setString("play");
    menu[0].setCharacterSize(15);
    menu[0].setFillColor(Color::White);
    menu[0].setPosition(x + 15, y + 42);

    // how to play — opens new rectangle to run tutorial
    menu[1].setFont(font);
    menu[1].setString("how to play");
    menu[1].setCharacterSize(15);
    menu[1].setFillColor(Color::White);
    menu[1].setPosition(x + 15, y + 65);

    // controls button — opens new rectangle to show controls
    menu[2].setFont(font);
    menu[2].setString("controls");
    menu[2].setCharacterSize(15);
    menu[2].setFillColor(Color::White);
    menu[2].setPosition(x + 15, y + 90);

    // save button
    menu[3].setFont(font);
    menu[3].setString("save");
    menu[3].setCharacterSize(15);
    menu[3].setFillColor(Color::White);
    menu[3].setPosition(x + 15, y + 115);

    selectedOption = 0;
    menu[selectedOption].setFillColor(Color::Yellow);
  };

  void draw(RenderWindow* win) {
    win->draw(*background);
    win->draw(title);
    for (int i = 0; i < maxOption; i++) {
      win->draw(menu[i]);
    }
  };

  void drawHtp(RenderWindow* win) {
    howToPlayText.setFont(font);
    howToPlayText.setString(
        "How To Play: \n\n\n"
        "Using the buy menu you can buy different plant seeds!\n\n\n"
        "Be careful not to use all your money on seeds, some plants need \n\n\n"
        "certain harvest equipment:\n\n\n"
        "\n\n\n"
        "Potatoes need a shovel to dig up.\n\n\n"
        "Carrots needs gloves to pull up. \n\n\n"
        "All berries need no harvest equipment. \n\n\n"
        "\n\n\n"
        "You can move your player and plant the plant seeds where you \n\n\n"
        "stand (make sure the right seeds are highlighted in your \n\n\n"
        "hotbar to plant!)\n\n\n"
        "\n\n\n"
        "Don't forget to water your seeds once you plant them. Water \n\n\n"
        "plants daily by standing over the plant, the plant will grow  \n\n\n"
        "at the start of a new day. If a plant wasn't watered it will \n\n\n"
        "die and vanish.\n\n\n"
        "\n\n\n"
        "Once a plant has reached full growth you can harvest when \n\n\n"
        "standing over the plant (don't forget to have the right harvest \n\n\n"
        "equipment highlighted in the hotbar!).\n\n\n"
        "\n\n\n"
        "You can sell your harvested plants in the sell menu (make sure \n\n\n"
        "you have the right plant highlighted in the hotbar). \n\n\n"
        "\n\n\n"
        "Enjoy the game!");
    howToPlayText.setCharacterSize(8);
    howToPlayText.setFillColor(Color::Black);
    howToPlayText.setPosition(40, 90);
    win->draw(*howToPlayBg);
    win->draw(howToPlayText);
  }

  void drawControl(RenderWindow* win) {
    controlText.setFont(font);
    controlText.setString(
        "Controls: Press special keys to activate\n\n\n\n\n"
        "Arrows: navigate menus \n\n\n\n"
        "Enter: commits choice \n\n\n\n"
        "Escape: exit menus \n\n\n\n"
        "M: re-enter main menu \n\n\n\n"
        "B: buy menu \n\n\n\n"
        "N: sell menu \n\n\n\n"
        "P: plant seed \n\n\n\n"
        "1: water plant\n\n\n\n"
        "2: harvest plant \n\n\n\n"
        "0: skip to next day \n\n\n\n"
        "Space bar: loop through inventory \n\n\n\n"
        "\n\n"
        "Player Movement: \n\n\n"
        "W: up \n\n\n"
        "A: left \n\n\n"
        "S: down \n\n\n"
        "D: right \n\n\n");

    controlText.setCharacterSize(8);
    controlText.setFillColor(Color::Black);
    controlText.setPosition(250, 90);
    win->draw(*controlBg);
    win->draw(controlText);
  }

  void drawSave(RenderWindow* win) { win->draw(*saveBg); }

  void drawWallet(RenderWindow* win, Player* player) {
    int tempNo = player->get_shells();
    walletNumber = std::to_string(tempNo);  // converting int to string
    wallet.setFont(font);
    wallet.setString("shells: " + walletNumber);  // concatenating the string
    wallet.setCharacterSize(10);
    wallet.setFillColor(Color::White);
    wallet.setPosition(290, 275);
    win->draw(wallet);
  }

  virtual void moveDown() {
    // checking array
    if (selectedOption + 1 < maxOption) {
      // changing text colour
      menu[selectedOption].setFillColor(sf::Color::White);
      // iterating array
      selectedOption++;
      // changing text colour
      menu[selectedOption].setFillColor(sf::Color::Yellow);
    } else if (selectedOption == 3) {
      menu[selectedOption].setFillColor(sf::Color::Yellow);
    } else {
      selectedOption = 0;
      menu[selectedOption].setFillColor(sf::Color::Yellow);
    }
  }
  virtual void moveUp() {
    // checking array
    if (selectedOption - 1 >= 0) {
      menu[selectedOption].setFillColor(sf::Color::White);
      selectedOption--;
      // changing text colour
      menu[selectedOption].setFillColor(sf::Color::Yellow);
    } else {
      selectedOption = 0;
    }
  }

  // changing visibility

  bool get_walletVisibility() { return walletVisibility; }
  void set_walletVisibility(bool visible) { walletVisibility = visible; }

  void set_visibility(bool visible) { turnOn = visible; }
  bool get_visibility() { return turnOn; }

  void set_htpVisi(bool visible) { howToPlayVisible = visible; }
  bool get_htpVisi() { return howToPlayVisible; }

  void set_controlVisi(bool visible) { controlVisible = visible; }
  bool get_controlVisi() { return controlVisible; }

  void set_saveVisi(bool visible) { saveVisible = visible; }
  bool get_saveVisi() { return saveVisible; }
  void setPressed(int selected) { selectedOption = selected; }
  int menuPressed() { return selectedOption; }
  // ~Menu();
};
#endif