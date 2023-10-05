#include <SFML/Graphics.hpp>
#ifndef PLANT_H
#define PLANT_H
#include <iostream>

#include "tile.h"
using namespace sf;

// when making each subclass like blueberries thats when in the constructor you
// initialise the protected values
class Plant : public tile {
 protected:
  int growTime;
  int seedingTime;  // how many days ago it was seeded
  int costPrice;
  int sellPrice;
  // int hydrationLevel;  // value 1 is watered, value 0 needs to be watered, -1
                       // means its now dead
  bool alive;
  int growthStage;  // associated with time after planting, needs to be rounded
                    // to days to be correlated with growTime
  int harvestEquipment;
  Texture growthImage;

 public:
  Plant(int _x, int _y) : tile::tile(_x, _y) {
    x = _x;
    y = _y;
    int size = 50;
    isPlantable = false; //cannot plant ontop of another plant tile
    square = new RectangleShape(Vector2f(size, size));
    growthImage.loadFromFile("textures/cheese.png");
    square->setTexture(&growthImage);
    square->setTextureRect(IntRect(0, 0, size, size));
    if (!growthImage.loadFromFile("textures/cheese.png")) {
      std::cout << "error loading texture" << std::endl;
    }
    square->setPosition(_x, _y);
    // tile::set_texture(imageDescription);
    // necessary values
    growthStage = 0;
    alive = true;
    hydrationLevel = 0;
    seedingTime = 0;
    // this->imageDescription = imageDescription;

    // arbitrary placeholder values (initialise everything to 0)
    growTime = 0;
    costPrice = 0;
    sellPrice = 0;
    yield = 0;
    harvestEquipment = 0;
  };

  Plant() : Plant(0, 0){};

  // for testing no pure virtual functions allowed
  // may need to be changed into just a virtual function in the tile class
  
  virtual int harvestYield() = 0;

  // plant growth for each new day
  void newDayGrowth() {
    if (hydrationLevel == 0) {
      alive = false;
    }
    //hydration level may conflict and be taken away twice with the grow() function
    hydrationLevel--;
    seedingTime++;
    return;
  };

  void killPlant() {
    if (hydrationLevel < 0) {
      alive = false;
    }
    return;
  };


  // Identifying the name of the plant:



  // checks plant meets criteria and makes it grow
  // virtual void grow() {
  //   if (hydrationLevel == 1 && alive && growthStage < growTime) {
  //     hydrationLevel = 0;
  //     growthStage++;
  //   //   int size = 50;
  //   //   square = new RectangleShape(Vector2f(size, size));
  //   //   growthImage.loadFromFile(imageDescription);
  //   //   square->setTexture(&growthImage);
  //   //   square->setTextureRect(IntRect(0, 0, size, size));
  //   //   if (!growthImage.loadFromFile(imageDescription)) {
  //   //     std::cout << "error loading texture" << std::endl;
  //   //   }
  //   //   square->setPosition(x, y);
  //   //   this->imageDescription = imageDescription;
  //   }
  //   return;
  // }

  // The setters
  void set_growTime(int growTime) {
    this->growTime = growTime;
    return;
  };
  void set_seedingTime(int seedingTime) {
    this->seedingTime = seedingTime;
    return;
  };
  void set_costPrice(int costPrice) {
    this->costPrice = costPrice;
    return;
  };
  void set_sellPrice(int sellPrice) {
    this->sellPrice = sellPrice;
    return;
  };
  // void set_hydrationLevel(int hydrationLevel) {
  //   this->hydrationLevel = hydrationLevel;
  //   return;
  // };
  void set_alive(bool alive) {
    this->alive = alive;
    return;
  };
  void set_growthStage(int growthStage) {
    this->growthStage = growthStage;
    return;
  };
  void set_yield(int yield) {
    this->yield = yield;
    return;
  };
  void set_harvestEquipment(int harvestEquipment) {
    this->harvestEquipment = harvestEquipment;
    return;
  };
  // void set_imageDescription(std::string imageDescription) {
  //   this->imageDescription = imageDescription;
  //   return;
  // };

  // The getters
  int get_growTime() { return growTime; };
  int get_seedingTime() { return seedingTime; };
  int get_costPrice() { return costPrice; };
  int get_sellPrice() { return sellPrice; };
  // int get_hydrationLevel() { return hydrationLevel; };
  bool get_alive() { return alive; };
  int get_growthStage() { return growthStage; };
  int get_yield() { return yield; };
  int get_harvestEquipment() { return harvestEquipment; };

  ~Plant(){};
};

#endif