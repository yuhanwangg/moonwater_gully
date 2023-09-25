#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Player.h"
#include "PlayerInteraction.h"
#include "tile.h"
class PlayerInteraction_driver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Player* player;

 public:
  PlayerInteraction_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
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
            player->seedPlant(1, *player, &background);
          }

        }

      }
      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      }
      win->display();
    }
  };
};


int main() {
    PlayerInteraction_driver driver(600, "TEST");
    driver.make_background();
    driver.run();
    return 0;
};

