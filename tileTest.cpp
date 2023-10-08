#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "tile.h"

class tileDriver {
 private:
  RenderWindow* win;
  //   tile** background = new tile*[400];  // array of tile pointers
  std::vector<tile*> background;

 public:
  tileDriver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
  };

  void makeBackground() {
    for (int r = 0; r < 600; r += 50) {
      for (int c = 0; c < 600; c += 50) {
        tile* newTile = new tile(r, c);  // Pass coordinates to
                                         // tile constructor
        background.push_back(newTile);
      }
    }
    background[10]->set_texture("textures/grass_texture.png");
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
  //   ~tileDriver();

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {
  tileDriver driver(600, "TEST");
  driver.makeBackground();
  driver.run();
  return 0;
}