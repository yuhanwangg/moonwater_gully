#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"


int main() {
  Game game(600, "Moonwater Gully");
  game.makeBackground();
  game.run();
  return 0;
}