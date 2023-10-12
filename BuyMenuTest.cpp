#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "BuyMenu.h"
#include "Menu.h"
#include "Player.h"
#include "tile.h"

class BuyMenuDriver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Player* player;
  Menu menu = Menu(300, 150);
  BuyMenu buymenu = BuyMenu(250, 400);
  bool visibleMenu = true;
  bool visibleBuy = false;

 public:
  BuyMenuDriver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
    visibleBuy = false;
    visibleMenu = true;
  };

  void makeBackground() {
    //Crates game background
    for (int r = 0; r < 600; r += 50) {
      for (int c = 0; c < 600; c += 50) {
        tile* newTile = new tile(r, c);  // Pass coordinates to tile constructor
        background.push_back(newTile);
      }
    }
    return;
  };

  void run() {
    // Runs the game
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
          }
          if (Keyboard::isKeyPressed(Keyboard::Down)) {
            menu.moveDown();
            buymenu.moveDown();
            buymenu.set_successCheck(false);
            buymenu.set_failureCheck(false);
          }
          if (Keyboard::isKeyPressed(Keyboard::Return) &&
              (visibleMenu == true)) {
            // opening the rectangles of the options
            int selection = menu.menuPressed();
            switch (selection) {
              case 0:
                // close the menu and access game window
                visibleMenu = false;
                menu.set_visibility(visibleMenu);
                break;
              case 1:
                // open game description
                menu.set_visibility(false);
                menu.set_htpVisi(true);
                break;
              case 2:
                // open controls rectangle
                menu.set_visibility(false);
                menu.set_controlVisi(true);
                break;
              case 3:
                // open save confirmation
                menu.set_visibility(false);
                menu.set_saveVisi(true);
                break;
            }
          }
          if (Keyboard::isKeyPressed(Keyboard::Return) &&
              (visibleBuy == true)) {
            // opening the rectangles of the options
            int itemNo = buymenu.get_buySelect();
            switch (itemNo) {
              case 0:
                if (buymenu.purchaseStatus(player, 0) == true) {
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
                if (buymenu.purchaseStatus(player, 1) == true) {
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
                if (buymenu.purchaseStatus(player, 2) == true) {
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
                if (buymenu.purchaseStatus(player, 3) == true) {
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
                if (buymenu.purchaseStatus(player, 4) == true) {
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
                if (buymenu.purchaseStatus(player, 5) == true) {
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
        }
      }

      win->clear();

      // player movement
      if (Keyboard::isKeyPressed(Keyboard::A)) {
        player->moveLeft();
      }
      if (Keyboard::isKeyPressed(Keyboard::D)) {
        player->moveRight();
      }
      if (Keyboard::isKeyPressed(Keyboard::W)) {
        player->moveUp();
      }
      if (Keyboard::isKeyPressed(Keyboard::S)) {
        player->moveDown();
      }

      // testing of keyboard for menu toggling

      if (Keyboard::isKeyPressed(Keyboard::B) && (visibleMenu == false)) {
        visibleBuy = true;
        buymenu.set_buyOn(visibleBuy);
      }

      if (Keyboard::isKeyPressed(Keyboard::M) && (visibleBuy == false)) {
        if ((menu.get_controlVisi() == false) &&
            (menu.get_htpVisi() == false) && (menu.get_saveVisi() == false)) {
          visibleMenu = true;
          menu.set_visibility(visibleMenu);
        }
      }

      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      }

      // visibility of menus
      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        if (visibleBuy == false) {
          menu.set_controlVisi(false);
          menu.set_htpVisi(false);
          menu.set_saveVisi(false);

        } else {
          visibleBuy = false;
          buymenu.set_failureCheck(false);
          buymenu.set_successCheck(false);
          buymenu.set_buyOn(false);
          visibleMenu = false;
          menu.set_visibility(visibleMenu);
        }
      }

      player->draw(win);

      // drawing the menus

      if (menu.get_visibility() == true) {
        menu.draw(win);
      }
      // drawing htp pop up
      if (menu.get_htpVisi() == true) {
        menu.drawHtp(win);
      }
      if (menu.get_controlVisi() == true) {
        menu.drawControl(win);
      }
      if (menu.get_saveVisi() == true) {
        menu.drawSave(win);
      }
      if (buymenu.get_buyOn() == true) {
        buymenu.draw(win);
      }

      // drawing purchase success or failure
      if (buymenu.get_failureCheck() == true) {
        buymenu.drawPurchaseError(win);
      }
      if (buymenu.get_successCheck() == true) {
        buymenu.drawPurchaseSuccess(win);
      }

      win->display();
    }
    return;
  };

  
  
  // getter
  std::vector<tile*> get_background() { return background; }

  ~BuyMenuDriver(){};
};

int main() {
  BuyMenuDriver driver(600, "TEST");
  driver.makeBackground();
  driver.run();
  return 0;
}