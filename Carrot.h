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
            harvestEquipment = 2; // need level 2 harvest equipment to harvest
            sellPrice = 80; // sells for 80 bells
            growthImage.loadFromFile("textures/carrotSeeds.png");
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/carrotSeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        Carrot(): RootPlant(0,0){}; 

        // changes growth image and plant values if growth criteria has been met
        void grow() {
            if (hydrationLevel == 1 && alive && growthStage < growTime) {
                hydrationLevel = 0;
                growthStage++;
                int size = 50;
                square = new RectangleShape(Vector2f(size, size));
                // sets the growth image depending on its growth stage
                switch(growthStage) {
                    case 1: 
                        imageDescription = "textures/carrot.png";
                        break;
                    default: // to know when it breaks it plants cheese
                        imageDescription = "textures/cheese.png";
                        break;
                }
                // loads the growth image
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
