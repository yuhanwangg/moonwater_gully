#include "BerryPlant.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Plant.h"
#include "tile.h"
using namespace sf;

// g++ Plant.cpp -o plant -I include -L lib -l sfml-system -l sfml-window -l
// sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
class tile_driver {
 private:
  RenderWindow* win;
  //   tile** background = new tile*[400];  // array of tile pointers
  std::vector<tile*> background;
  BerryPlant bp = BerryPlant(100, 100);

 public:
  tile_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    bp.set_sellPrice(40);
    bp.set_harvestEquipment(2);
    bp.set_hydrationLevel(1);

    // bp.grow();
  };

  void make_background() {
    for (int r = 0; r < 600; r += 50) {
      for (int c = 0; c < 600; c += 50) {
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
      bp.draw(win);

      win->display();
    }
  };
  //   ~tile_driver();

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {
  BerryPlant bp1(50, 50);

  std::cout << "The berry plant has a cost price of 70:" << bp1.get_costPrice()
            << ", a sell price of 0:" << bp1.get_sellPrice()
            << ", a growTime of 2:" << bp1.get_growTime()
            << ", and requires havestEquipment level 0:"
            << bp1.get_harvestEquipment() << std::endl;

  bp1.harvestYield();

  std::cout << "The berry plant has harvest yield of (number 3-6):"
            << bp1.get_yield() << std::endl;

  bp1.killPlant();

  std::cout << "The berry plant has hydration level 0:"
            << bp1.get_hydrationLevel()
            << ", and is alive (should be 1):" << bp1.get_alive() << std::endl;

  bp1.set_hydrationLevel(1);
  std::cout << "The berry plant has hydration level 1:"
            << bp1.get_hydrationLevel()
            << ", and is alive (should be 1):" << bp1.get_alive() << std::endl;

  // don't know how to change it so it updates everytime it runs to show first
  // blueberry picture then new grow picture?
  bp1.grow();

  //  NOT OUTPUTTING IMAGE DESCRIPTION??
  std::cout << "the berryplant is in growthStage 1:" << bp1.get_growthStage()
            << ", has hydration level 0: " << bp1.get_hydrationLevel()
            << ", and image description carrotSeeds.png:"
            << bp1.get_imageDescription() << std::endl;

  bp1.newDayGrowth();
  std::cout << "The berry plant has hydration level -1:"
            << bp1.get_hydrationLevel()
            << ", The berry plant was seeded 1 day ago:"
            << bp1.get_seedingTime()
            << ", plant is alive (should be 0):" << bp1.get_alive()
            << std::endl;

  bp1.grow();
  std::cout << "the berry plant is in growthStage 1:" << bp1.get_growthStage()
            << ", has hydration level -1: " << bp1.get_hydrationLevel()
            << std::endl;

  BerryPlant bp2(50, 50);
  // test to see that it doesn't exceed growth of 3
  bp2.set_hydrationLevel(1);
  bp2.grow();
  bp2.set_hydrationLevel(1);
  bp2.grow();
  bp2.set_hydrationLevel(1);
  bp2.grow();
  //   this should determine if it exceeds growth to 4
  bp2.set_hydrationLevel(1);
  bp2.grow();
  std::cout << "the berryplant is in growthStage 2:" << bp2.get_growthStage()
            << std::endl;

  tile_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}
