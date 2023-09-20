#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "tile_test.h"

class tile_driver {
 private:
  RenderWindow* win;
  tile** background = new tile*[400];  // array of tile pointers

 public:
  tile_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
  };

  void make_background() {
    for (int i = 0; i < 400; i++) {
      for (int r = 0; r < 600; r = r + 30) {
        for (int c = 0; c < 600; c = c + 30) {
          background[i] = new tile(r, c);
          background[i]->draw(win);
        }
      }
    }
    int count = 0;
    // for (int r = 0; r < 600; r = r + 30) {
    //   for (int c = 0; c < 600; c = c + 30) {
    //     // background[count]->set_x(r);
    //     // background[count]->set_y(c);
    //     background[count]->draw(win);
    //     count++;
    //   }
    // }
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