#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Blueberry.h"
#include "BuyMenu.h"
#include "Carrot.h"
#include "Day.h"
#include "Menu.h"
#include "Player.h"
#include "PlayerInteraction.h"
#include "Potato.h"
#include "Strawberry.h"
#include "tile.h"
using namespace sf;
#include "BuyMenu.h"
#include "Inventory.h"
#include "Menu.h"
#include "Player.h"
#include "tile.h"

class everything_driver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Player* player;
  Menu menu = Menu(300, 150);
  BuyMenu buymenu = BuyMenu(250, 400);
  bool visible_menu = true;
  bool visible_buy = false;
  Inventory inventory = Inventory(550, 50);
  Day day;
  PlayerInteraction PI;

 public:
  everything_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
    visible_buy = false;
    visible_menu = true;
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
          if (Keyboard::isKeyPressed(Keyboard::P)) {
            switch (inventory.get_inventoryIndex()) {
              case 2:
                if (inventory.get_blueberrySeedsCount() > 0) {
                  PI.seedPlant(2, *player, &background);
                  inventory.subtract_blueberrySeedsCount();
                }
                break;
              case 4;
                if (inventory.get_strawberrySeedsCount() > 0) {
              PI.seedPlant(4, *player, &background);
              inventory.subtract_strawberrySeedsCount();
            }
              break;
              case 6;
                if (inventory.get_potatoSeedsCount() > 0) {
              PI.seedPlant(6, *player, &background);
              inventory.subtract_potatoSeedsCount();
            }
              break;
              case 8;
                if (inventory.get_carrotSeedsCount() > 0) {
              PI.seedPlant(8, *player, &background);
              inventory.subtract_SeedsCount();
            }
              break
            }
          }
        }

        if (e.type == Event::KeyPressed) {
          if (Keyboard::isKeyPressed(Keyboard::Num1)) {
            PI.waterPlant(*player, &background);
            std::cout << "watered plant" << std::endl;

            int player_x = (floor(player->get_x() / 50) * 50);
            int player_y = (floor(player->get_y() / 50) * 50);

            for (int i = 0; i < 144; i++) {
              if (background[i]->get_x() == player_x &&
                  background[i]->get_y() == player_y) {
                (*background[i]).grow();
              }
            }
          }
        }

        if (e.type == Event::KeyPressed) {
          if (Keyboard::isKeyPressed(Keyboard::Up)) {
            menu.moveUp();
            buymenu.moveUp();
            buymenu.set_successCheck(false);  // visibility remove
            buymenu.set_failureCheck(false);
          }
          if (Keyboard::isKeyPressed(Keyboard::Down)) {
            menu.moveDown();
            buymenu.moveDown();
            buymenu.set_successCheck(false);
            buymenu.set_failureCheck(false);
          }

          if (Keyboard::isKeyPressed(Keyboard::Space)) {
            inventory.scrollInventory();
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

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->subtract_50shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";  // next up, add items into the player's
                                      // inventory
                  inventory.add_carrotSeedsCount();
                  std::cout << "Carrot seeds in inventory: "
                            << inventory.get_carrotSeedsCount() << std::endl;
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 1:
                if (buymenu.purchase_status(player, 1) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->subtract_50shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";

                  inventory.add_potatoSeedsCount();
                  std::cout << "Potato seeds in inventory: "
                            << inventory.get_potatoSeedsCount() << std::endl;
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 2:
                if (buymenu.purchase_status(player, 2) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->subtract_70shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";

                  inventory.add_strawberrySeedsCount();

                  std::cout << "Strawberry seeds in inventory: "
                            << inventory.get_strawberrySeedsCount()
                            << std::endl;
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 3:
                if (buymenu.purchase_status(player, 3) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->subtract_70shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";

                  inventory.add_blueberrySeedsCount();

                  std::cout << "Blueberry seeds in inventory: "
                            << inventory.get_blueberrySeedsCount() << std::endl;
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 4:
                if (buymenu.purchase_status(player, 4) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->subtract_400shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";

                  inventory.add_shovelCount();
                  std::cout
                      << "Shovels in inventory: " << inventory.get_shovelCount()
                      << std::endl;
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              case 5:
                if (buymenu.purchase_status(player, 5) == true) {
                  buymenu.set_successCheck(true);
                  buymenu.set_failureCheck(false);

                  std::cout << "Shells: " << player->get_shells();
                  std::cout << "\n";
                  player->subtract_150shells();
                  std::cout << "Remaining shells: " << player->get_shells();
                  std::cout << "\n";

                  inventory.add_gloveCount();
                  std::cout
                      << "Gloves in inventory: " << inventory.get_gloveCount()
                      << std::endl;
                } else {
                  buymenu.set_successCheck(false);
                  buymenu.set_failureCheck(true);
                }
                break;
              default:
                std::cout << "Error in purchase" << std::endl;
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

      if (Keyboard::isKeyPressed(Keyboard::B) && (visible_menu == false)) {
        visible_buy = true;
        buymenu.set_buyOn(visible_buy);
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

      inventory.drawInventory(win);

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

      // drawing purchase success or failure
      if (buymenu.get_failureCheck() == true) {
        buymenu.draw_purchaseError(win);
      }
      if (buymenu.get_successCheck() == true) {
        buymenu.draw_purchaseSuccess(win);
      }

      // drawing the clock
      day.drawDayDracker(win);
      day.dayCountdown();

      win->display();
    }
  };

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {
  everything_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}