#include <SFML/Graphics.hpp>
#ifndef STRAWBERRY_H
#define STRAWBERRY_H
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include "BerryPlant.h"
#include <cstdlib>
#include <ctime>

using namespace sf;

class Strawberry: public BerryPlant {
    public:
        Strawberry(int _x, int _y): BerryPlant( _x, _y) {
            harvestEquipment = 1;
            sellPrice = 200;
            growthImage.loadFromFile("textures/carrotSeeds.png"); //change to different seed texture for each plant type
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/carrotSeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        Strawberry(): BerryPlant(0,0){}; 

        void grow() {
            if (hydrationLevel == 1 && alive && growthStage < growTime) {
                hydrationLevel = 0;
                growthStage++;
                int size = 50;
                square = new RectangleShape(Vector2f(size, size));
                switch(growthStage) {
                    case 1:
                        imageDescription = "textures/seedling.png"; 
                        break;

                    case 2:
                        imageDescription = "textures/strawberry.png"; // image from https://www.istockphoto.com/vector/wild-strawberries-on-a-bush-growing-in-a-bed-pixel-art-icon-old-school-8-bit-gm926753458-254277720
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
