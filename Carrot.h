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
            imageDescription = "textures/carrotSeeds.png";
            className = "Carrot";
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
            std::cout << "hydration level: " << hydrationLevel << " alive: " << alive << std::endl;
            // if (hydrationLevel == 0) {
            //     std::cout << "hydradtion level working" << std::endl;
            // }
            // if (alive) {
            //     std::cout << "alive working" << std::endl;
            // }

            // if (growthStage < growTime) {
            //     std::cout << "growStage working" << std::endl;
            // }
            if (hydrationLevel == 0 && alive && growthStage <= growTime) {
                // std::cout << "growing" << std::endl;
                // hydrationLevel = 0;
                // growthStage++;
                int size = 50;
                square = new RectangleShape(Vector2f(size, size));
                // sets the growth image depending on its growth stage
                switch(growthStage) {
                    case 1: 
                        imageDescription = "textures/carrotGrown.png";
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
                
            } 
            //else if (hydrationLevel == 0){

            //     killPlant();
            //     growthImage.loadFromFile(imageDescription);
            //     square->setTexture(&growthImage);
            //     square->setTextureRect(IntRect(0, 0, size, size));
            //     if (!growthImage.loadFromFile(imageDescription)) {
            //         std::cout << "error loading texture" << std::endl;
            //     }
            //     square->setPosition(x, y);
            // }

        }; 
};

#endif
