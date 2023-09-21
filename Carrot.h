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
        Carrot(int _x, int _y, std::string imageDescription): RootPlant( _x, _y, imageDescription) {
            harvestEquipment = 2;
            sellPrice = 80;
        };

        Carrot(): RootPlant(0,0, "textures/grass_texture_light.png"){}; 

};

#endif
