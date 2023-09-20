#include <SFML/Graphics.hpp>
#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include "tile_test.h"
using namespace sf;

class Plant: public tile {
    protected:
        int growTime;
        int seedingTime;
        int costPrice;
        int sellPrice;
        int hydrationLevel;
        bool alive = true;
        std::string harvestEquipment;
        int growthStage;
        int yield;
        sf::Texture image;

    public:
        Plant();
        Plant(int _x, int _y, std::string imageDescription): tile::tile(_x,_y){
            image.loadFromFile(imageDescription);
            square->setTexture(&image);
        }
        virtual int harvestYield() = 0;
        virtual void changeImage() {
            
        };


        


};

#endif 