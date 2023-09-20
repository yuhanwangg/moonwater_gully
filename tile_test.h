#include <SFML/Graphics.hpp>
#ifndef TILE_TEST
#define TILE_TEST
#include <iostream>
using namespace sf;

class tile {
 private:
  int x, y;
  int size;
  RectangleShape* square;
  // texture placeholder
 public:
  tile(int _x, int _y) {
    x = _x;
    y = _y;
    size = 30;
    square = new RectangleShape(Vector2f(size, size));
    square->setFillColor(Color::Green);
    square->setPosition(x, y);
  };
  void set_x(int _x) { x = _x; };
  void set_y(int _y) { y = _y; };

  tile() : tile(0, 0) { size = 30; };

  void draw(RenderWindow* win) { win->draw(*square); };

  ~tile();
};

#endif