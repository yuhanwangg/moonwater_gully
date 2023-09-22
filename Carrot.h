#include <SFML/Graphics.hpp>
#ifndef CARROT_H
#define CARROT_H
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include "RootPlant.h"
#include <cstdlib>
#include <ctime>

using namespace sf;

class Carrot: public RootPlant {
    public:
        Carrot(int _x, int _y): RootPlant( _x, _y) {
            harvestEquipment = 2;
            sellPrice = 80;
            growthImage.loadFromFile("textures/carrotSeeds.png");
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/carrotSeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        Carrot(): RootPlant(0,0){}; 

};

#endif
