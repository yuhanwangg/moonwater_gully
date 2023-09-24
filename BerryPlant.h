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
            growTime = 2; // takes 2 days to grow
            costPrice = 70; // cost 70 shells to buy
            growthImage.loadFromFile("textures/carrotSeeds.png");  // starting seed image
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/carrotSeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        BerryPlant(): BerryPlant(0,0){}; 

        // yield is random value between 3-6
        int harvestYield () {
            srand(time(NULL)); // This code needs to only be put in once, in the main file 
            yield = (rand() %3 ) +3;
            return yield;
        }
};

#endif
