#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "Blueberry.h"
#include "BuyMenu.h"
#include "Carrot.h"
#include "Day.h"
#include "Menu.h"
#include "Player.h"
#include "PlayerInteraction.h"
#include "Potato.h"
#include "Strawberry.h"
#include "tile.h"
using namespace sf;
#include "BuyMenu.h"
#include "Inventory.h"
#include "Menu.h"
#include "Player.h"
#include "SaveGame.h"
#include "SellMenu.h"
#include "tile.h"

int main() {
  std::vector<tile*> background;
  Player* player;
  Inventory inventory = Inventory(550, 55);
  Day day;
  SaveGame save = SaveGame(background, &inventory, player, &day);

  player = new Player(10, 50, 50);

  for (int r = 0; r < 600; r += 50) {
    for (int c = 0; c < 600; c += 50) {
      tile* newTile = new tile(r, c);  // Pass coordinates to tile constructor
      background.push_back(newTile);
    }
  }

  save.open_saveFile();
}