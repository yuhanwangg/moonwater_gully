#include <SFML/Graphics.hpp>
#ifndef BLUEBERRY_H
#define BLUEBERRY_H
#include <iostream>
#include "tile.h"
#include "Plant.h"
#include "BerryPlant.h"
#include <cstdlib>
#include <ctime>

using namespace sf;

class Blueberry: public BerryPlant {
    public:
        Blueberry(int _x, int _y): BerryPlant( _x, _y) {
            harvestEquipment = 1; // need level 1 harvest equipment to harvest
            sellPrice = 120; // sells for 120 shells
            imageDescription = "textures/blueberrySeeds.png";
            className = "Blueberry";
            growthImage.loadFromFile("textures/blueberrySeeds.png");
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/blueberrySeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        Blueberry(): BerryPlant(0,0){}; 

        // changes growth image and plant values if growth criteria has been met
        void grow() {
            if (hydrationLevel == 0 && alive && growthStage <= growTime) {
                // hydrationLevel = 0;
                // growthStage++;
                int size = 50;
                square = new RectangleShape(Vector2f(size, size));
                // sets new growth image for each stage of growth
                switch(growthStage) {
                    case 1:
                        imageDescription = "textures/blueberrySeedling.png";
                        break;

                    case 2:
                        imageDescription = "textures/blueberrybushGrown.png"; // image from https://www.linkedin.com/posts/michael-mollica-47383a175_been-working-for-a-while-on-foliage-for-a-activity-6982498457068482560-dIGK/?trk=public_profile_like_view
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
