#include <SFML/Graphics.hpp>
#ifndef ROOTPLANT_H
#define ROOTPLANT_H
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include <cstdlib>
#include <ctime>

using namespace sf;

class RootPlant: public Plant {
    public:
        RootPlant(int _x, int _y, std::string imageDescription): Plant( _x, _y, imageDescription) {
            growTime = 1;
            costPrice = 50;
        };

        RootPlant(): RootPlant(0,0, "textures/grass_texture_light.png"){}; 

        int harvestYield () {
            srand(time(NULL)); // This code needs to only be put in once, in the main file 
            yield = (rand() %3 ) +1;
            return yield;
        }
};

#endif
