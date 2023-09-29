#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "BuyMenu.h"
#include "Menu.h"
#include "Player.h"
#include "SellMenu.h"
#include "tile.h"

class SellMenu_driver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Player* player;
  Menu menu = Menu(300, 150);
  BuyMenu buymenu = BuyMenu(250, 400);
  SellMenu sellmenu = SellMenu(250, 300);
  Inventory inventory = Inventory(550, 50);
  bool visible_menu = true;
  bool visible_buy = false;
  bool visible_sell = false;

 public:
  SellMenu_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
    visible_buy = false;
    visible_menu = true;
    visible_sell = false;
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
            buymenu.set_successCheck(false);  // visibility remove
            buymenu.set_failureCheck(false);

            sellmenu.moveUp();
            sellmenu.set_successCheck(false);
            sellmenu.set_successCheck(false);
          }
          if (Keyboard::isKeyPressed(Keyboard::Down)) {
            menu.moveDown();
            buymenu.moveDown();
            buymenu.set_successCheck(false);
            buymenu.set_failureCheck(false);

            sellmenu.moveDown();
            sellmenu.set_successCheck(false);
            sellmenu.set_failureCheck(false);
          }
          if (Keyboard::isKeyPressed(Keyboard::Return) &&
              (visible_menu == true)) {
            // opening the rectangles of the options
            int selection = menu.menuPressed();
            switch (selection) {
              case 0:
                // close the menu and access game window
                visible_menu = false;
                menu.set_visibility(visible_menu);
                break;
              case 1:
                // open game description
                menu.set_visibility(false);
                menu.set_htp_visi(true);
                break;
              case 2:
                // open controls rectangle
                menu.set_visibility(false);
                menu.set_control_visi(true);
                break;
              case 3:
                // open save confirmation
                menu.set_visibility(false);
                menu.set_save_visi(true);
                break;
            }
          }
          if (Keyboard::isKeyPressed(Keyboard::Return) &&
              (visible_buy == true)) {
            // opening the rectangles of the options
            int item_no = buymenu.get_buySelect();
            switch (item_no) {
              case 0:
                if (buymenu.purchase_status(player, 0) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);
                  int wallet = player->get_shells();
                  std::cout << "Shells: " << wallet;
                  std::cout << "\n";
                  player->set_shells(wallet - 50);
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";  // next up, add items into the player's
                                      // inventory
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 1:
                if (buymenu.purchase_status(player, 1) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);
                  int wallet = player->get_shells();
                  std::cout << "Shells: " << wallet;
                  std::cout << "\n";
                  player->set_shells(wallet - 50);
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 2:
                if (buymenu.purchase_status(player, 2) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);
                  int wallet = player->get_shells();
                  std::cout << "Shells: " << wallet;
                  std::cout << "\n";
                  player->set_shells(wallet - 70);
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 3:
                if (buymenu.purchase_status(player, 3) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);
                  int wallet = player->get_shells();
                  std::cout << "Shells: " << wallet;
                  std::cout << "\n";
                  player->set_shells(wallet - 70);
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 4:
                if (buymenu.purchase_status(player, 4) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);
                  int wallet = player->get_shells();
                  std::cout << "Shells: " << wallet;
                  std::cout << "\n";
                  player->set_shells(wallet - 300);
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 5:
                if (buymenu.purchase_status(player, 5) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);
                  int wallet = player->get_shells();
                  std::cout << "Shells: " << wallet;
                  std::cout << "\n";
                  player->set_shells(wallet - 150);
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              default:
                std::cout << "Error in purchase" << std::endl;
            }
          }

          if (Keyboard::isKeyPressed(Keyboard::Return) &&
              (visible_sell == true)) {
            // opening the rectangles of the options
            int item_no = sellmenu.get_sellSelect();
            switch (item_no) {
              case 0:
                if (sellmenu.purchase_status(&inventory, 0) == true) {
                  sellmenu.set_successCheck(true);
                  sellmenu.set_failureCheck(false);

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->add_100shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";  // next up, add items into the player's
                                      // inventory
                } else {
                  sellmenu.set_successCheck(false);
                  sellmenu.set_failureCheck(true);
                }
                break;
              case 1:
                if (sellmenu.purchase_status(&inventory, 1) == true) {
                  sellmenu.set_successCheck(true);
                  sellmenu.set_failureCheck(false);

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->add_80shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";  // next up, add items into the player's
                                      // inventory
                } else {
                  sellmenu.set_successCheck(false);
                  sellmenu.set_failureCheck(true);
                }
                break;
              case 2:
                if (sellmenu.purchase_status(&inventory, 2) == true) {
                  sellmenu.set_successCheck(true);
                  sellmenu.set_failureCheck(false);

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->add_200shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";  // next up, add items into the player's
                                      // inventory
                } else {
                  sellmenu.set_successCheck(false);
                  sellmenu.set_failureCheck(true);
                }
                break;
              case 3:
                if (sellmenu.purchase_status(&inventory, 3) == true) {
                  sellmenu.set_successCheck(true);
                  sellmenu.set_failureCheck(false);

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->add_120shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";  // next up, add items into the player's
                                      // inventory
                } else {
                  sellmenu.set_successCheck(false);
                  sellmenu.set_failureCheck(true);
                }
                break;
              default:
                std::cout << "Error in selling." << std::endl;
            }
          }
        }
      }

      win->clear();

      // player movement
      if (Keyboard::isKeyPressed(Keyboard::A)) {
        player->move_left();
      }
      if (Keyboard::isKeyPressed(Keyboard::D)) {
        player->move_right();
      }
      if (Keyboard::isKeyPressed(Keyboard::W)) {
        player->move_up();
      }
      if (Keyboard::isKeyPressed(Keyboard::S)) {
        player->move_down();
      }

      // testing of keyboard for menu toggling

      if (Keyboard::isKeyPressed(Keyboard::B) && (visible_menu == false) &&
          (visible_sell == false)) {
        visible_buy = true;
        buymenu.set_buyOn(visible_buy);
      }

      if (Keyboard::isKeyPressed(Keyboard::O) && (visible_menu == false) &&
          (visible_buy == false)) {
        visible_sell = true;
        sellmenu.set_sellOn(visible_sell);
      }

      if (Keyboard::isKeyPressed(Keyboard::M) && (visible_buy == false)) {
        if ((menu.get_control_visi() == false) &&
            (menu.get_htp_visi() == false) && (menu.get_save_visi() == false)) {
          visible_menu = true;
          menu.set_visibility(visible_menu);
        }
      }

      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      }

      // visibility of menus
      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        if (visible_buy == false) {
          menu.set_control_visi(false);
          menu.set_htp_visi(false);
          menu.set_save_visi(false);

        } else {
          visible_buy = false;
          buymenu.set_failureCheck(false);
          buymenu.set_successCheck(false);
          buymenu.set_buyOn(false);

          visible_sell = false;
          sellmenu.set_failureCheck(false);
          sellmenu.set_successCheck(false);
          sellmenu.set_sellOn(false);

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

      if (sellmenu.get_sellOn() == true) {
        sellmenu.draw(win);
      }

      // drawing purchase success or failure
      if (buymenu.get_failureCheck() == true) {
        buymenu.draw_purchaseError(win);
      }
      if (buymenu.get_successCheck() == true) {
        buymenu.draw_purchaseSuccess(win);
      }

      // drawing selling success or failure
      if (sellmenu.get_failureCheck() == true) {
        sellmenu.draw_sellFailure(win);
      }
      if (sellmenu.get_successCheck() == true) {
        sellmenu.draw_sellSuccess(win);
      }

      inventory.drawInventory(win);

      win->display();
    }
  };

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {
  SellMenu_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}