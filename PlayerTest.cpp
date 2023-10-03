#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Plant.h"
#include "Player.h"
#include "tile.h"

class Player_driver {
 private:
  RenderWindow* win;
  std::vector<tile*> background;
  // creation of player class
  Player* player;
  Plant p1 = Plant(50, 50);

 public:
  Player_driver(int size, std::string title) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    player = new Player(10, 50, 50);
    // player->add_plant(plant);
    p1.set_costPrice(20);
    p1.set_sellPrice(40);
    p1.set_growTime(3);
    p1.set_harvestEquipment(2);
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
      // Plant* inventory = player->get_plant_inventory();
      // std::cout << "Plant in inventory: " << inventory[0];
      // << std::endl;

      // drawing the tiles
      for (auto tilePtr : background) {
        tilePtr->draw(win);
      };
      player->draw(win);
      p1.draw(win);

      win->display();
    }
  };

  std::vector<tile*> get_background() { return background; };
};

int main() {
  Player_driver driver(600, "TEST");
  driver.make_background();
  driver.run();
  return 0;
}
