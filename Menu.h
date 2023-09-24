#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Menu {
 protected:
  // rectangle shape for menu size
  RectangleShape* background;
  RectangleShape* how_to_play_bg;
  RectangleShape* control_bg;
  RectangleShape* save_bg;

  Texture bg_texture;

  bool how_to_play_visible;
  bool control_visible;
  bool save_visible;
  bool isMainMenuOpen;
  Font font;
  Text title;

  int x, y;
  int selected_option;
  int length, width;
  int max_option;
  Text menu[4];
  bool turnOn;

 public:
  Menu(int len, int wid) {
    length = len;
    width = wid;
    x = 25;
    y = 25;
    max_option = 4;
    turnOn = true;

    how_to_play_visible = false;
    control_visible = false;
    save_visible = false;
    isMainMenuOpen = false;

    // creating background — maybe change into another function
    background = new RectangleShape(Vector2f(length, width));
    background->setPosition(x, y);

    // how to play image
    how_to_play_bg = new RectangleShape(Vector2f(550, 550));
    how_to_play_bg->setFillColor(Color::White);
    how_to_play_bg->setPosition(x, y);

    // controls image
    control_bg = new RectangleShape(Vector2f(250, 450));
    control_bg->setFillColor(Color::Blue);
    control_bg->setPosition(325, 25);

    save_bg = new RectangleShape(Vector2f(length, width));
    save_bg->setPosition(150, 150);

    // loading in textures:
    bg_texture.loadFromFile("textures/main_menu.png");
    background->setTexture(&bg_texture);
    save_bg->setTexture(&bg_texture);
    save_bg->setTextureRect(IntRect(0, 0, len, wid));
    background->setTextureRect(IntRect(0, 0, len, wid));

    // loading font
    font.loadFromFile("textures/font_texture/TTF/dogica.ttf");
    if (!font.loadFromFile("textures/font_texture/TTF/dogica.ttf")) {
      std::cout << "error loading font" << std::endl;  // error testing
    }

    // buidling the title text
    title.setFont(font);
    title.setString("Moonwater Gulley");
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

    selected_option = 0;
    menu[selected_option].setFillColor(Color::Yellow);
  };

  void draw(RenderWindow* win) {
    win->draw(*background);
    win->draw(title);
    for (int i = 0; i < max_option; i++) {
      win->draw(menu[i]);
    }
  };

  void draw_htp(RenderWindow* win) { win->draw(*how_to_play_bg); }

  void draw_control(RenderWindow* win) { win->draw(*control_bg); }

  void draw_save(RenderWindow* win) { win->draw(*save_bg); }

  void moveDown() {
    // checking array
    if (selected_option + 1 < max_option) {
      // changing text colour
      menu[selected_option].setFillColor(sf::Color::White);
      // iterating array
      selected_option++;
      // changing text colour
      menu[selected_option].setFillColor(sf::Color::Yellow);
    } else if (selected_option == 3){
      menu[selected_option].setFillColor(sf::Color::Yellow);
    }
      else {
      selected_option = 0;
      menu[selected_option].setFillColor(sf::Color::Yellow);
    }
  }
  void moveUp() {
    // checking array
    if (selected_option - 1 >= 0) {
      menu[selected_option].setFillColor(sf::Color::White);
      selected_option--;
      // changing text colour
      menu[selected_option].setFillColor(sf::Color::Yellow);
    } else {
      selected_option = 0;
    }
  }

      // changing visibility

      void set_visibility(bool visible){ turnOn = visible;}
      bool get_visibility() { return turnOn; }

      void set_htp_visi(bool visible) { how_to_play_visible = visible; }
      bool get_htp_visi() { return how_to_play_visible; }

      void set_control_visi(bool visible) { control_visible = visible; }
      bool get_control_visi() { return control_visible; }

      void set_save_visi(bool visible) { save_visible = visible; }
      bool get_save_visi() { return save_visible; }
      void setPressed(int selected) { selected_option = selected; }
      int menuPressed() { return selected_option; }
    // ~Menu();
  };
#endif
