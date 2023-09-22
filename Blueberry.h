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
            harvestEquipment = 1;
            sellPrice = 120;
            growthImage.loadFromFile("textures/carrotSeeds.png");
            square->setTexture(&growthImage);
            square->setTextureRect(IntRect(0, 0, size, size));
            if (!growthImage.loadFromFile("textures/carrotSeeds.png")) {
            std::cout << "error loading texture" << std::endl;
            }
            square->setPosition(_x, _y);
        };

        Blueberry(): BerryPlant(0,0){}; 

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
                        imageDescription = "textures/blueberrybush.png"; // image from https://www.linkedin.com/posts/michael-mollica-47383a175_been-working-for-a-while-on-foliage-for-a-activity-6982498457068482560-dIGK/?trk=public_profile_like_view
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
