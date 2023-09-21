#include <SFML/Graphics.hpp>
#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include "tile.h"
using namespace sf;

//when making each subclass like blueberries thats when in the constructor you initialise the protected values
class Plant: public tile {
    protected:
        int growTime; 
        int seedingTime; // how many days ago it was seeded 
        int costPrice;
        int sellPrice;
        int hydrationLevel; //value 1 is watered, value 0 needs to be watered, -1 means its now dead
        bool alive;
        int growthStage; // associated with time after planting, needs to be rounded to days to be correlated with growTime
        int yield;
        int harvestEquipment;
        std::string imageDescription;

    public:
        
        Plant(int _x, int _y, std::string imageDescription): tile::tile(_x,_y) {
            tile::set_texture(imageDescription);
            growthStage = 0;
            alive = true;
            hydrationLevel = 0;
            seedingTime = 0;
            };

        Plant(): Plant(0, 0, "textures/grass_texture_light.png"){};
        
        // for testing no pure virtual functions allowed
        // virtual int harvestYield() = 0; 

        void newDayGrowth() {
            hydrationLevel--;
            seedingTime++;
            return;
        };

        void killPlant() {
            if (hydrationLevel < 0) {
                alive = false;
            }
            return;
        };

        // checks plant meets criteria and makes it grow 
        void grow(std::string imageDescription) {
            if(hydrationLevel == 1 && alive && growthStage < growTime) {
                hydrationLevel = 0;
                growthStage++;
                this->imageDescription = imageDescription;
            }
            return;
        }


        // The setters
        void set_growTime(int growTime) {
            this->growTime = growTime;
            return;
        };
        void set_seedingTime(int seedingTime) {
            this->seedingTime = seedingTime;
            return;
        };
        void set_costPrice(int costPrice) {
            this->costPrice = costPrice;
            return;
        };
        void set_sellPrice(int sellPrice) {
            this->sellPrice = sellPrice;
            return;
        };
        void set_hydrationLevel(int hydrationLevel) {
            this->hydrationLevel = hydrationLevel;
            return;
        };
        void set_alive(bool alive) {
            this->alive = alive;
            return;
        };
        void set_growthStage(int growthStage) {
            this->growthStage= growthStage;
            return;
        };
        void set_yield(int yield) {
            this->yield= yield;
            return;
        };
        void set_harvestEquipment(int harvestEquipment) {
            this->harvestEquipment = harvestEquipment;
            return;
        };
        void set_imageDescription(std::string imageDescription) {
            this->imageDescription = imageDescription;
            return;
        };

        // The getters
        int get_growTime() {
            return growTime;
        };
        int get_seedingTime() {
            return seedingTime;
        };
        int get_costPrice() {
            return costPrice;
        };
        int get_sellPrice() {
            return sellPrice;
        };
        int get_hydrationLevel() {
            return hydrationLevel;
        };
        bool get_alive() {
            return alive;
        };
        int get_growthStage() {
            return growthStage;
        };
        int get_yield() {
            return yield;
        };
        int get_harvestEquipment() {
            return harvestEquipment;
        };
        std::string get_imageDescription() {
            return imageDescription;
        };


        ~Plant(){};

};

#endif 