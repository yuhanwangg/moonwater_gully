#include <SFML/Graphics.hpp>
#ifndef POTATO_H
#define POTATO_H
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include "RootPlant.h"
#include <cstdlib>
#include <ctime>

using namespace sf;

class Potato: public RootPlant {
    public:
        Potato(int _x, int _y): RootPlant( _x, _y) {
            harvestEquipment = 3;
            sellPrice = 100;
            growthImage.loadFromFile("textures/carrotSeeds.png");
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/carrotSeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        Potato(): RootPlant(0,0){}; 

        void grow() {
            if (hydrationLevel == 1 && alive && growthStage < growTime) {
                hydrationLevel = 0;
                growthStage++;
                int size = 50;
                square = new RectangleShape(Vector2f(size, size));
                switch(growthStage) {
                    case 1:
                        imageDescription = "textures/potato.png";
                        break;
                    default:
                        imageDescription = "textures/potato.png";
                        break;
                }
                growthImage.loadFromFile(imageDescription);
                square->setTexture(&growthImage);
                square->setTextureRect(IntRect(0, 0, size, size));
                if (!growthImage.loadFromFile(imageDescription)) {
                    std::cout << "error loading texture" << std::endl;
                }
                square->setPosition(x, y);
                
            };

        };

};

#endif
