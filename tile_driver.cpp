#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "tile_test.h"

class tile_driver {
 private:
  RenderWindow* win;
  //   tile** background = new tile*[400];  // array of tile pointers
  std::vector<tile*> background;

 public:
  tile_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
  };

  void make_background() {
    // for (int i = 0; i < 400; i++) {
    //   background[i] = new tile();
    // }
    for (int r = 0; r < 600; r += 30) {
      for (int c = 0; c < 600; c += 30) {
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

      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      }

      win->display();
    }
  };
  //   ~tile_driver();
};

int main() {
  tile_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}