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
        RootPlant(int _x, int _y): Plant( _x, _y) {
            growTime = 1;
            costPrice = 50;
            growthImage.loadFromFile("textures/carrotSeeds.png");
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/carrotSeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        RootPlant(): RootPlant(0,0){}; 

        int harvestYield () {
            srand(time(NULL)); // This code needs to only be put in once, in the main file 
            yield = (rand() %3 ) +1;
            return yield;
        }
};

#endif
