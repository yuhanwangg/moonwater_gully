#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Day.h"
#include "Player.h"
#include "tile.h"

class Day_driver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Player* player;
  Day day;

 public:
  Day_driver(int size, std::string title) {
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

      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      }


      player->draw(win);

      // drawing the clock
      day.drawDayDracker(win);
      day.dayCountdown(&background);


      win->display();
    }
  };

  // setters and getters

  std::vector<tile*> get_background() { return background; };
};

int main() {
  Day_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}