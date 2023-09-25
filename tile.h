#include <SFML/Graphics.hpp>
#ifndef TILE_H
#define TILE_H
#include <iostream>
using namespace sf;

class tile {
 protected:
  int x, y;
  int size;
  RectangleShape* square;
  Texture grass;
  bool isPlantable;
  // texture placeholder
 public:
  tile(int _x, int _y) {
    x = _x;
    y = _y;
    size = 50;
    isPlantable = true;
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

  int get_x() {return x;};
  int get_y() {return y;};

  void set_texture(std::string Texture_name) {
    Texture* texture;
    texture->loadFromFile(Texture_name);
    square->setTexture(texture);
    square->setTextureRect(IntRect(0, 0, size, size));
    if (!texture->loadFromFile(Texture_name)) {
      std::cout << "error loading texture" << std::endl;
    };
  }

  // setter for colour/texture

  tile() : tile(0, 0) { size = 50; };

  void draw(RenderWindow* win) { win->draw(*square); };

  ~tile(){};
};

#endif