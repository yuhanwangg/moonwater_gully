#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include "RootPlant.h"
#include "Potato.h"
using namespace sf;


//g++ RootPlant.cpp -o rootplant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
class tileDriver {
 private:
  RenderWindow* win;
  //   tile** background = new tile*[400];  // array of tile pointers
  std::vector<tile*> background;
  Potato p = Potato(350, 350);

 public:
  tileDriver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    p.set_hydrationLevel(1);
    
    //uncomment to see potato grow
    //p.grow();
  };

  void makeBackground() {
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
      p.draw(win);

      win->display();
    }
  };
  //   ~tileDriver();

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {

  Potato p1(50,50);

  std::cout << "The potato plant has a cost price of 50:" << p1.get_costPrice() << ", a sell price of 100:" << p1.get_sellPrice() << ", a growTime of 1:" << p1.get_growTime() << ", requires havestEquipment level 1:" << p1.get_harvestEquipment() << ", and has image description textures/potatoSeeds.png:" << p1.get_imageDescription() << std::endl;

  p1.harvestYield();

  std::cout << "The potato plant has harvest yield of (number 1-3):" << p1.get_yield() << std::endl;

  // p1.killPlant();

  std::cout << "The potato plant has hydration level 0:" << p1.get_hydrationLevel() << ", and is alive (should be 1):" << p1.get_alive() << std::endl; 

  p1.set_hydrationLevel(1);
  std::cout << "The potato plant has hydration level 1:" << p1.get_hydrationLevel() << ", and is alive (should be 1):" << p1.get_alive() << std::endl;


  // don't know how to change it so it updates everytime it runs to show first blueberry picture then new grow picture?
  p1.grow();
  p1.newDayGrowth();

  std::cout << "the potato is in growthStage 1:" << p1.get_growthStage() << ", has hydration level 0: " << p1.get_hydrationLevel() << ", and image description textures/potatoGrown.png:" << p1.get_imageDescription() << std::endl;


  p1.newDayGrowth();
  std::cout << "The potato plant has hydration level -1:" << p1.get_hydrationLevel() << ", The root plant was seeded 2 days ago:" << p1.get_seedingTime() <<", plant is alive (should be 0):" << p1.get_alive() << std::endl;


  p1.grow();
  p1.newDayGrowth();
  std::cout << "the potato plant is in growthStage 1:" << p1.get_growthStage() << ", has hydration level -2: " << p1.get_hydrationLevel() << ", and image description textures/potatGrown.png:" << p1.get_imageDescription() << std::endl;



  Potato p2(50,50);
  // test to see that it doesn't exceed growth of 1
  p2.set_hydrationLevel(1);
  p2.newDayGrowth();
  p2.set_hydrationLevel(1);
  p2.newDayGrowth();
  p2.set_hydrationLevel(1);
  p2.newDayGrowth();
  p2.set_hydrationLevel(1);
  p2.newDayGrowth();
  std::cout << "the rootplant is in growthStage 1:" << p2.get_growthStage() << std::endl;


  tileDriver driver(600, "TEST");
  driver.makeBackground();
  driver.run();
  return 0;
}
