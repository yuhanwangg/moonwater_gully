#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "BuyMenu.h"
#include "Menu.h"
#include "Player.h"
#include "tile.h"

class BuyMenu_driver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Player* player;
  Menu menu = Menu(300, 150);
  BuyMenu buymenu = BuyMenu(200, 400);
  bool visible_menu = true;
  bool visible_buy = false;
  bool htp_vis = false;
  bool control_vis = false;
  bool save_vis = false;

 public:
  BuyMenu_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
    visible_buy = false;
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
            buymenu.moveUp();
            // break;
          }
          if (Keyboard::isKeyPressed(Keyboard::Down)) {
            menu.moveDown();
            buymenu.moveDown();
            // break;
          }
          if (Keyboard::isKeyPressed(Keyboard::Return) &&
              (visible_menu == true)) {
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

      // testing of keyboard for menu toggling
      if (Keyboard::isKeyPressed(Keyboard::B)) {
        visible_buy = true;
        buymenu.set_buyOn(visible_buy);
      }

      if (Keyboard::isKeyPressed(Keyboard::M)) {
        if ((control_vis == false) && (htp_vis == false) &&
            (save_vis == false)) {
          visible_menu = true;
          menu.set_visibility(visible_menu);
        }
      }

      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      }

      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        if (visible_buy == false) {
          control_vis = false;
          menu.set_control_visi(control_vis);
          htp_vis = false;
          menu.set_htp_visi(htp_vis);
          save_vis = false;
          menu.set_save_visi(save_vis);

        } else {
          visible_buy = false;
          buymenu.set_buyOn(false);
          visible_menu = false;
          menu.set_visibility(visible_menu);
        }
      }

      player->draw(win);

      // drawing the menus
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

      if (buymenu.get_buyOn() == true) {
        buymenu.draw(win);
      }

      win->display();
    }
  };

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {
  BuyMenu_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}