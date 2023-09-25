#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include "BerryPlant.h"
#include "Strawberry.h"
using namespace sf;


//g++ RootPlant.cpp -o rootplant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
class tile_driver {
 private:
  RenderWindow* win;
  //   tile** background = new tile*[400];  // array of tile pointers
  std::vector<tile*> background;
  Strawberry s = Strawberry(150, 150);

 public:
  tile_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    s.set_hydrationLevel(1);
    // uncomment to see strawberry growth
    // s.grow();
    // s.set_hydrationLevel(1);
    // s.grow();
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
      s.draw(win);

      win->display();
    }
  };
  //   ~tile_driver();

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {

  Strawberry s1(50,50);

  std::cout << "The strawbery plant has a cost price of 70:" << s1.get_costPrice() << ", a sell price of 200:" << s1.get_sellPrice() << ", a growTime of 2:" << s1.get_growTime() << ", requires havestEquipment level 1:" << s1.get_harvestEquipment() << ", and has image description textures/strawberrySeeds.png:" << s1.get_imageDescription() << std::endl;

  s1.harvestYield();

  std::cout << "The strawberry plant has harvest yield of (number 3-6):" << s1.get_yield() << std::endl;

  s1.killPlant();

  std::cout << "The strawberry plant has hydration level 0:" << s1.get_hydrationLevel() << ", and is alive (should be 1):" << s1.get_alive() << std::endl; 

  s1.set_hydrationLevel(1);
  std::cout << "The strawyberry plant has hydration level 1:" << s1.get_hydrationLevel() << ", and is alive (should be 1):" << s1.get_alive() << std::endl;


  // don't know how to change it so it updates everytime it runs to show first blueberry picture then new grow picture?
  s1.grow();

  std::cout << "the strawberry is in growthStage 1:" << s1.get_growthStage() << ", has hydration level 0: " << s1.get_hydrationLevel() << ", and image description strawberrySeedling.png:" << s1.get_imageDescription() << std::endl;


  s1.newDayGrowth();
  std::cout << "The blueberry plant has hydration level -1:" << s1.get_hydrationLevel() << ", The blueberry plant was seeded 1 day ago:" << s1.get_seedingTime() <<", plant is alive (should be 0):" << s1.get_alive() << std::endl;

  s1.set_alive(true);
  s1.set_hydrationLevel(1);
  s1.grow();
  std::cout << "the strawberry plant is in growthStage 2:" << s1.get_growthStage() << ", has hydration level 0: " << s1.get_hydrationLevel() << ", and image description strawberrybushGrown.png:" << s1.get_imageDescription() << std::endl;

  Strawberry s2(50,50);
  // test to see that it doesn't exceed growth of 3
  s2.set_hydrationLevel(1);
  s2.grow();
  s2.set_hydrationLevel(1);
  s2.grow();
  s2.set_hydrationLevel(1);
  s2.grow();
//   this should determine if it exceeds growth to 4
  s2.set_hydrationLevel(1);
  s2.grow();
  std::cout << "the strawberry is in growthStage 2:" << s2.get_growthStage() << std::endl;


  tile_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}
