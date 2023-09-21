#include <SFML/Graphics.hpp>
#ifndef BERRYPLANT_H
#define BERRYPLANT_H
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include <cstdlib>
#include <ctime>

using namespace sf;

class BerryPlant: public Plant {
    public:
        BerryPlant(int _x, int _y, std::string imageDescription): Plant( _x, _y, imageDescription) {
            growTime = 3;
            costPrice = 70;
        };

        BerryPlant(): BerryPlant(0,0, "textures/grass_texture_light.png"){}; 

        int harvestYield () {
            srand(time(NULL)); // This code needs to only be put in once, in the main file 
            yield = (rand() %3 ) +3;
            return yield;
        }
};

#endif
