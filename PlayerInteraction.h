#ifndef PLAYERINTERACTION_H
#define PLAYERINTERACTION_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Player.h"
#include "Plant.h"
#include "Carrot.h"
#include "Potato.h"
#include "Blueberry.h"
#include "Strawberry.h"
#include "tile.h"

class PlayerInteraction {
    public:
        PlayerInteraction() {};

        void seedPlant(std::string seedType, Player p, std::vector<tile>*backgroundTiles) {
            for (int i = 0; i < 144; i++) {
                if (backgroundTiles[i].get_x() == p.get_x() && backgroundTiles[i].get_y() == p.get_y()){
                    
                }
            }
            switch(seedType) {
            case "carrot":
                Carrot c(p.get_x(), p.get_y());
                break;
            default:
                break;



            }
            return;
        };
};




#endif