#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.h"
#include "Plant.h"
using namespace sf;



//g++ Plant.cpp -o plant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
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
    for (int r = 0; r < 600; r += 50) {
      for (int c = 0; c < 600; c += 50) {
        tile* newTile = new tile(r, c);  // Pass coordinates to
                                         // tile constructor
        background.push_back(newTile);
      }
    }
    background[20]->set_texture("textures/grass_texture.png");
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

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {

  Plant p1(50,50, "textures/grass_texture_light.png");

  p1.set_costPrice(20);
  p1.set_sellPrice(40);
  p1.set_growTime(3);
  p1.set_harvestEquipment(2);


  std::cout << "The plant has a cost price of 20:" << p1.get_costPrice() << ", a sell price of 40:" << p1.get_sellPrice() << ", a growTime of 3:" << p1.get_growTime() << ", and requires havestEquipment level 2:" << p1.get_harvestEquipment() << std::endl;

  p1.killPlant();

  std::cout << "The plant has hydration level 0:" << p1.get_hydrationLevel() << ", and is alive (should be 1):" << p1.get_alive() << std::endl; 

  p1.set_hydrationLevel(1);
  std::cout << "The plant has hydration level 1:" << p1.get_hydrationLevel() << ", and is alive (should be 1):" << p1.get_alive() << std::endl;


  // don't know how to change it so it updates everytime it runs to show first blueberry picture then new grow picture?
  p1.grow("textures/grass_texture_light.png");

  std::cout << "the plant is in growthStage 1:" << p1.get_growthStage() << ", has hydration level 0: " << p1.get_hydrationLevel() << ", and image description grass_texture_light.png:" << p1.get_imageDescription() << std::endl;


  p1.newDayGrowth();
  p1.killPlant();
  std::cout << "The plant has hydration level -1:" << p1.get_hydrationLevel() << ", The plant was seeded 1 day ago:" << p1.get_seedingTime() <<", plant is alive (should be 0):" << p1.get_alive() << std::endl;

  p1.grow("textures/grass_texture_dark.png");
  std::cout << "the plant is in growthStage 1:" << p1.get_growthStage() << ", has hydration level -1: " << p1.get_hydrationLevel() << ", and image description grass_texture_light.png:" << p1.get_imageDescription() << std::endl;



  tile_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}
