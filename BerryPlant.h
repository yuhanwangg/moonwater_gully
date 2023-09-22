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
        BerryPlant(int _x, int _y): Plant( _x, _y) {
            growTime = 2;
            costPrice = 70;
            growthImage.loadFromFile("textures/carrotSeeds.png");
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/carrotSeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        BerryPlant(): BerryPlant(0,0){}; 

        int harvestYield () {
            srand(time(NULL)); // This code needs to only be put in once, in the main file 
            yield = (rand() %3 ) +3;
            return yield;
        }
};

#endif
