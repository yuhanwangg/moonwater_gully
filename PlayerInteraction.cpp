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
  PlayerInteraction PI;

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
            PI.seedPlant(1, *player, &background);
          }
        }
      }
      win->clear();

      // player movement
      if (Keyboard::isKeyPressed(Keyboard::A)) {
        player->move_left();
      } else if (Keyboard::isKeyPressed(Keyboard::D)) {
        player->move_right();
      } else if (Keyboard::isKeyPressed(Keyboard::W)) {
        player->move_up();
      } else if (Keyboard::isKeyPressed(Keyboard::S)) {
        player->move_down();
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
    PlayerInteraction_driver driver(600, "TEST");
    driver.make_background();
    driver.run();
    return 0;
};

