#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include "BerryPlant.h"
#include "Strawberry.h"
using namespace sf;



class TileDriver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  Strawberry s = Strawberry(100, 100);

 public:
  TileDriver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    s.set_hydrationLevel(1);
    
    // uncomment to see each growth stage
    s.grow();
    s.set_hydrationLevel(1);
    s.grow();
  };

  void makeBackground() {
    // Creates game background
    for (int r = 0; r < 600; r += 50) {
      for (int c = 0; c < 600; c += 50) {
        tile* newTile = new tile(r, c);  // Pass coordinates to tile constructor
        background.push_back(newTile);
      }
    }
    return;
  };

  void run() {
    // Runs game
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
    return;
  };
 

  //getter

  std::vector<tile*> get_background() { return background; }
  ~TileDriver(){};
};

int main() {

  Strawberry s1(50,50);

  std::cout << "The Strawberry plant has a cost price of 70:" << s1.get_costPrice() << ", a sell price of 200:" << s1.get_sellPrice() << ", a growTime of 2:" << s1.get_growTime() << ", requires havestEquipment level 1:" << s1.get_harvestEquipment() << ", and has image description textures/StrawberrySeeds.png:" << s1.get_imageDescription() << std::endl;

  s1.harvestYield();

  std::cout << "The Strawberry plant has harvest yield of (number 3-6):" << s1.get_yield() << std::endl;

  std::cout << "The Strawberry plant has hydration level 0:" << s1.get_hydrationLevel() << ", and is alive (should be 1):" << s1.get_alive() << std::endl; 

  s1.set_hydrationLevel(1);
  std::cout << "The Strawberry plant has hydration level 1:" << s1.get_hydrationLevel() << ", and is alive (should be 1):" << s1.get_alive() << std::endl;


  s1.newDayGrowth();
  s1.grow();
  

  std::cout << "the Strawberry is in growthStage 1:" << s1.get_growthStage() << ", has hydration level 0: " << s1.get_hydrationLevel() << ", and image description StrawberrySeedling.png:" << s1.get_imageDescription() << std::endl;


  s1.newDayGrowth();
  std::cout << "The Strawberry plant has hydration level -1:" << s1.get_hydrationLevel() << ", The Strawberry plant was seeded 2 days ago:" << s1.get_seedingTime() <<", plant is alive (should be 0):" << s1.get_alive() << std::endl;

  s1.set_alive(true);
  s1.set_hydrationLevel(1);
  s1.newDayGrowth();
  s1.grow();
  std::cout << "the Strawberry plant is in growthStage 2:" << s1.get_growthStage() << ", has hydration level 0: " << s1.get_hydrationLevel() << ", and image description StrawberrybushGrown.png:" << s1.get_imageDescription() << std::endl;

  Strawberry s2(50,50);
  // test to see that it doesn't exceed growth of 2
  s2.set_hydrationLevel(1);
  s2.newDayGrowth();
  s2.set_hydrationLevel(1);
  s2.newDayGrowth();
  s2.set_hydrationLevel(1);
  s2.newDayGrowth();
  s2.set_hydrationLevel(1);
  s2.newDayGrowth();
  std::cout << "the Strawberry is in growthStage 2:" << s2.get_growthStage() << std::endl;


  
  // Ensuring that it catches error thrown in carrot
  Strawberry s3(150,150);
  
  s3.set_hydrationLevel(1);
  s3.newDayGrowth();

  try {s3.grow();
    s3.set_hydrationLevel(1);
    s3.newDayGrowth();
  } catch (const char * msg) {
    std::cerr << msg << std::endl;
  }

  TileDriver driver(600, "TEST");
  driver.makeBackground();
  driver.run();
  return 0;
}
