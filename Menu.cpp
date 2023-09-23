#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "menu.h"
#include "Player.h"
#include "tile.h"

class Menu_driver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Player* player;
  Menu menu = Menu(300, 150);
  bool visible_menu = true;
  bool htp_vis = false;
  bool control_vis = false;
  bool save_vis = false;

 public:
  Menu_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
    visible_menu = true;
    htp_vis = false;
    control_vis = false;
    save_vis = false;
  };

  void make_background() {
    for (int r = 0; r < 600; r += 50) {
      for (int c = 0; c < 600; c += 50) {
        tile* newTile = new tile(r, c);  // Pass coordinates to tile constructor
        background.push_back(newTile);
      }
    }
  };

  void run() {
    while (win->isOpen()) {
      Event e;
      while (win->pollEvent(e)) {
        if (e.type == Event::Closed) {
          win->close();
        }
        if (e.type == Event::KeyPressed) {
          if (Keyboard::isKeyPressed(Keyboard::Up)) {
            menu.moveUp();
            // break;
          }
          if (Keyboard::isKeyPressed(Keyboard::Down)) {
            menu.moveDown();
            // break;
          }
          if (Keyboard::isKeyPressed(Keyboard::Return)) {
            // opening the rectangles of the options
            int selection = menu.menuPressed();
            if (selection == 0) {
              // close the menu and access game window
              visible_menu = false;
              menu.set_visibility(visible_menu);
            }

            if (selection == 1) {
              // open game description
              visible_menu = false;
              menu.set_visibility(visible_menu);
              htp_vis = true;
              menu.set_htp_visi(htp_vis);
            }
            if (selection == 2) {
              // open controls rectangle
              visible_menu = false;
              menu.set_visibility(visible_menu);
              control_vis = true;
              menu.set_control_visi(control_vis);
            }
            if (selection == 3) {
              // open save confirmation
              visible_menu = false;
              menu.set_visibility(visible_menu);
              save_vis = true;
              menu.set_save_visi(save_vis);
            }
          }
        }
      }
      win->clear();

      if (Keyboard::isKeyPressed(Keyboard::A)) {
        player->move_left();
      } else if (Keyboard::isKeyPressed(Keyboard::D)) {
        player->move_right();
      } else if (Keyboard::isKeyPressed(Keyboard::W)) {
        player->move_up();
      } else if (Keyboard::isKeyPressed(Keyboard::S)) {
        player->move_down();
      }

      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        control_vis = false;
        menu.set_control_visi(control_vis);
        htp_vis = false;
        menu.set_htp_visi(htp_vis);
        save_vis = false;
        menu.set_save_visi(save_vis);
        visible_menu = true;
        menu.set_visibility(true);
      }

      if (Keyboard::isKeyPressed(Keyboard::M)) {
        visible_menu = true;
        menu.set_visibility(true);
      }

      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      }

      player->draw(win);

      // drawing the menu
      if (menu.get_visibility() == true) {
        menu.draw(win);
      }
      // drawing htp pop up
      if (menu.get_htp_visi() == true) {
        menu.draw_htp(win);
      }
      if (menu.get_control_visi() == true) {
        menu.draw_control(win);
      }

      if (menu.get_save_visi() == true) {
        menu.draw_save(win);
      }

      // drawing the menu

      win->display();
    }
  };

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {
  Menu_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}