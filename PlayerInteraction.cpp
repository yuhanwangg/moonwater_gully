#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Player.h"
#include "PlayerInteraction.h"
#include "tile.h"
#include <cmath>

class PlayerInteraction_driver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Player* player;
  // PlayerInteraction PI;

   

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

    sf::Clock clock;
    const sf::Time targetFrameTime = sf::seconds(1.0f / 60.0f);

    while (win->isOpen()) {
      Event e;
      while (win->pollEvent(e)) {
        if (e.type == Event::Closed) {
          win->close();
        }

        if (e.type == Event::KeyPressed) {
          if (Keyboard::isKeyPressed(Keyboard::P)) {
            player->seedPlant(6, &background);
          }
        }

        if (e.type == Event::KeyPressed) {
          if (Keyboard::isKeyPressed(Keyboard::Num1)) {
            player->waterPlant(&background);
            std::cout << "watered plant" << std::endl;

            int player_x = (floor(player->get_x()/50)*50);
            int player_y = (floor(player->get_y()/50)*50);

            for (int i = 0; i < 144; i++) {
              if (background[i]->get_x() == player_x && background[i]->get_y() == player_y) {
                (*background[i]).grow();
              }
            }
            
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

      // limit fps to 60:

      sf::Time elapsed = clock.getElapsedTime();
      if (elapsed < targetFrameTime) {
        sf::sleep(targetFrameTime - elapsed);
      }
      clock.restart();

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

