#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "BerryPlant.h"
#include "Plant.h"
#include "Player_plantInv.h"
#include "tile.h"

class Player_driver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  // creation of player class
  Player* player;
  BerryPlant* berry;

 public:
  Player_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
    player->add_plant(berry);
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

      if (Keyboard::isKeyPressed(Keyboard::A)) {
        player->move_left();
      } else if (Keyboard::isKeyPressed(Keyboard::D)) {
        player->move_right();
      } else if (Keyboard::isKeyPressed(Keyboard::W)) {
        player->move_up();
      } else if (Keyboard::isKeyPressed(Keyboard::S)) {
        player->move_down();
      }
      std::vector<Plant*> inventory = player->get_plant_inventory();
      std::cout << "Plant in inventory's : " << inventory[0]->get_growthStage()
                << std::endl;

      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      }
      player->draw(win);

      win->display();
    }
  };
  // ~Player_driver(){
  //     delete [] player;
  // }

  // setters and getters

  std::vector<tile*> get_background() { return background; }
};

int main() {
  Player_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
};
