#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include "RootPlant.h"
#include "Carrot.h"
using namespace sf;


//g++ RootPlant.cpp -o rootplant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
class tile_driver {
 private:
  RenderWindow* win;
  //   tile** background = new tile*[400];  // array of tile pointers
  std::vector<tile*> background;
  Carrot c = Carrot(300, 300);

 public:
  tile_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    c.set_hydrationLevel(1);
    
    //c.grow();
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
      c.draw(win);

      win->display();
    }
  };
  //   ~tile_driver();

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {

  Carrot c1(50,50);

  std::cout << "The carrot plant has a cost price of 50:" << c1.get_costPrice() << ", a sell price of 80:" << c1.get_sellPrice() << ", a growTime of 1:" << c1.get_growTime() << ", and requires havestEquipment level 2:" << c1.get_harvestEquipment() << std::endl;

  c1.harvestYield();

  std::cout << "The carrot plant has harvest yield of (number 1-3):" << c1.get_yield() << std::endl;

  c1.killPlant();

  std::cout << "The carrot plant has hydration level 0:" << c1.get_hydrationLevel() << ", and is alive (should be 1):" << c1.get_alive() << std::endl; 

  c1.set_hydrationLevel(1);
  std::cout << "The carrot plant has hydration level 1:" << c1.get_hydrationLevel() << ", and is alive (should be 1):" << c1.get_alive() << std::endl;


  // don't know how to change it so it updates everytime it runs to show first blueberry picture then new grow picture?
  c1.grow();

  std::cout << "the carrot is in growthStage 1:" << c1.get_growthStage() << ", has hydration level 0: " << c1.get_hydrationLevel() << ", and image description textures/carrot.png:" << c1.get_imageDescription() << std::endl;


  c1.newDayGrowth();
  std::cout << "The carrot plant has hydration level -1:" << c1.get_hydrationLevel() << ", The root plant was seeded 1 day ago:" << c1.get_seedingTime() <<", plant is alive (should be 0):" << c1.get_alive() << std::endl;

  c1.grow();
  std::cout << "the carrot plant is in growthStage 1:" << c1.get_growthStage() << ", has hydration level -1: " << c1.get_hydrationLevel() << ", and image description textures/carrot.png:" << c1.get_imageDescription() << std::endl;



  Carrot c2(50,50);
  // test to see that it doesn't exceed growth of 3
  c2.set_hydrationLevel(1);
  c2.grow();
  c2.set_hydrationLevel(1);
  c2.grow();
  c2.set_hydrationLevel(1);
  c2.grow();
//   this should determine if it exceeds growth to 4
  c2.set_hydrationLevel(1);
  c2.grow();
  std::cout << "the rootplant is in growthStage 1:" << c2.get_growthStage() << std::endl;


  tile_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}
