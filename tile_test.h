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
  sf::Texture grass;
  // texture placeholder
 public:
  tile(int _x, int _y) {
    x = _x;
    y = _y;
    size = 60;
    square = new RectangleShape(Vector2f(size, size));
    grass.loadFromFile("textures/grass_texture_light.png");
    square->setTexture(&grass);
    square->setTextureRect(IntRect(0, 0, size, size));
    if (!grass.loadFromFile("textures/grass_texture_light.png")) {
      std::cout << "error loading texture" << std::endl;
    }
    square->setPosition(x, y);
  };
  void set_x(int _x) { x = _x; };
  void set_y(int _y) { y = _y; };

  // setter for colour/texture

  tile() : tile(0, 0) { size = 60; };

  void draw(RenderWindow* win) { win->draw(*square); };

  ~tile();
};

#endif