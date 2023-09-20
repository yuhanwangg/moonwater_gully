#include <SFML/Graphics.hpp>
#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include "tile.h"
using namespace sf;

class Plant: public tile {
    protected:
        int growTime;
        int seedingTime;
        int costPrice;
        int sellPrice;
        int hydrationLevel;
        bool alive = true;
        int growthStage;
        int yield;
        std::string harvestEquipment;
        std::string imageDescription;

    public:
        Plant();
        Plant(int _x, int _y, std::string imageDescription): tile::tile(_x,_y, imageDescription){}
        virtual int harvestYield() = 0;

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
        void set_harvestEquipment(std::string harvestEqipment) {
            this->harvestEqipment = harvestEqipment;
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
        std::string get_harvestEquipment() {
            return harvestEqipment;
        };
        std::string get_imageDescription() {
            return imageDescription;
        };




        


};

#endif 