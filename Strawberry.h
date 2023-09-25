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
            harvestEquipment = 1; // requires harvest equipment level 1
            sellPrice = 200; // sells for 200 shells
            imageDescription = "textures/strawberrySeeds.png";
            growthImage.loadFromFile("textures/strawberrySeeds.png"); //change to different seed texture for each plant type
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/strawberrySeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        Strawberry(): BerryPlant(0,0){}; 
        
        // changes growth image and plant values if growth criteria has been met
        void grow() {
            if (hydrationLevel == 1 && alive && growthStage < growTime) {
                hydrationLevel = 0;
                growthStage++;
                int size = 50;
                square = new RectangleShape(Vector2f(size, size));
                // sets new image for each growth stage
                switch(growthStage) {
                    case 1:
                        imageDescription = "textures/strawberrySeedling.png"; 
                        break;

                    case 2:
                        imageDescription = "textures/strawberrybushGrown.png"; // image from https://www.istockphoto.com/vector/wild-strawberries-on-a-bush-growing-in-a-bed-pixel-art-icon-old-school-8-bit-gm926753458-254277720
                        break;
                    
                    default: // to know when it breaks it plants cheese
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
