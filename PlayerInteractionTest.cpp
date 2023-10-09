#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Player.h"
#include "PlayerInteraction.h"
#include "tile.h"
class PlayerInteractionDriver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Player* player;
  PlayerInteraction PI;

 public:
  PlayerInteractionDriver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
  };

  void makeBackground() {
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
            PI.seedPlant(2, *player, &background);
          }
        }

        if (e.type == Event::KeyPressed) {
          if (Keyboard::isKeyPressed(Keyboard::Num1)) {
            PI.waterPlant(*player, &background);
            std::cout << "watered plant" << std::endl;

            int playerX = (floor(player->get_x()/50)*50);
            int playerY = (floor(player->get_y()/50)*50);

            // moving to day function
            // for (int i = 0; i < 144; i++) {
            //     (*background[i]).grow();
            // }
            
          }
        }
      }
      win->clear();

      // player movement
      if (Keyboard::isKeyPressed(Keyboard::A)) {
        player->moveLeft();
      } else if (Keyboard::isKeyPressed(Keyboard::D)) {
        player->moveRight();
      } else if (Keyboard::isKeyPressed(Keyboard::W)) {
        player->moveUp();
      } else if (Keyboard::isKeyPressed(Keyboard::S)) {
        player->moveDown();
      }

      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      }
      player->draw(win);

      win->display();
    }
  };

  std::vector<tile*> get_background() { return background; };
};


int main() {
    PlayerInteractionDriver driver(600, "TEST");
    driver.makeBackground();
    driver.run();
    return 0;
};

