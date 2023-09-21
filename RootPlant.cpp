#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include "RootPlant.h"
using namespace sf;


//g++ RootPlant.cpp -o rootplant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
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

  RootPlant rp1(50,50, "textures/cheese.png");

  std::cout << "The root plant has a cost price of 50:" << rp1.get_costPrice() << ", a sell price of 0:" << rp1.get_sellPrice() << ", a growTime of 1:" << rp1.get_growTime() << ", and requires havestEquipment level 0:" << rp1.get_harvestEquipment() << std::endl;

  rp1.killPlant();

  std::cout << "The root plant has hydration level 0:" << rp1.get_hydrationLevel() << ", and is alive (should be 1):" << rp1.get_alive() << std::endl; 

  rp1.set_hydrationLevel(1);
  std::cout << "The root plant has hydration level 1:" << rp1.get_hydrationLevel() << ", and is alive (should be 1):" << rp1.get_alive() << std::endl;


  // don't know how to change it so it updates everytime it runs to show first blueberry picture then new grow picture?
  rp1.grow("textures/grass_texture_light.png");

  std::cout << "the rootplant is in growthStage 1:" << rp1.get_growthStage() << ", has hydration level 0: " << rp1.get_hydrationLevel() << ", and image description grass_texture_light.png:" << rp1.get_imageDescription() << std::endl;


  rp1.newDayGrowth();
  std::cout << "The root plant has hydration level -1:" << rp1.get_hydrationLevel() << ", The root plant was seeded 1 day ago:" << rp1.get_seedingTime() <<", plant is alive (should be 0):" << rp1.get_alive() << std::endl;

  rp1.grow("textures/grass_texture_dark.png");
  std::cout << "the root plant is in growthStage 1:" << rp1.get_growthStage() << ", has hydration level -1: " << rp1.get_hydrationLevel() << ", and image description grass_texture_light.png:" << rp1.get_imageDescription() << std::endl;




  tile_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}
