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
            harvestEquipment = 3; // need harvest equipment level 3 to harvest
            sellPrice = 100; // sells for 100 shells
            growthImage.loadFromFile("textures/carrotSeeds.png"); // this image can change later to correct seed colour
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/carrotSeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        Potato(): RootPlant(0,0){}; 

        // changes growth image and plant values if growth criteria has been met
        void grow() {
            if (hydrationLevel == 1 && alive && growthStage < growTime) {
                hydrationLevel = 0;
                growthStage++;
                int size = 50;
                square = new RectangleShape(Vector2f(size, size));
                // sets image to new growth image
                switch(growthStage) {
                    case 1: 
                        imageDescription = "textures/potato.png";
                        break;
                    default: // checks to see if program broke by planting cheese
                        imageDescription = "textures/cheese.png";
                        break;
                }
                // loads new growth image
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
