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
  int hydrationLevel;
  std::string imageDescription;
  std::string className;
  // texture placeholder
 public:
  tile(int _x, int _y) {
    x = _x;
    y = _y;
    size = 50;
    isPlantable = true;
    hydrationLevel = 0;
    imageDescription = "textures/grass_texture_light.png";
    className = "tile";
    square = new RectangleShape(Vector2f(size, size));
    grass.loadFromFile(imageDescription);
    square->setTexture(&grass);
    square->setTextureRect(IntRect(0, 0, size, size));
    if (!grass.loadFromFile(imageDescription)) {
      std::cout << "error loading texture" << std::endl;
    }
    square->setPosition(x, y);
  };

  virtual void grow(){};
  virtual void newDayGrowth(){};
  // virtual void killPlant(tile *backgroundTilePtr){};
  void set_x(int _x) { x = _x; };
  void set_y(int _y) { y = _y; };
  void set_isPlantable(bool isPlantable) {
    this->isPlantable = isPlantable;
  };
  void set_size(int size) {this->size = size;};
  void set_hydrationLevel(int hydrationLevel) {this->hydrationLevel = hydrationLevel;};


  int get_x() {return x;};
  int get_y() {return y;};
  bool get_isPlantable() {
    return isPlantable;
  };
  int get_size() {return size;};
  int get_hydrationLevel() {return hydrationLevel;}



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


  // Getters and Setters

  void set_imageDescription(std::string imageDescription) {
    this->imageDescription = imageDescription;
    return;
  };

  void set_className(std::string className) {
    this->className = className;
    return;
  }

  virtual int get_growthStage(){return 0;};
  std::string get_imageDescription() { return imageDescription; };
  std::string get_className() {return className; };
  
};

#endif