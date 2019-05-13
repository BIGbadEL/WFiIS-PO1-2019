#pragma once

#include "Car.h"

/**
 * @brief pozwal na towrzne bardzije szczegolwych obiektow typ  car a mianicoe Ford
 * 
 */

class Ford : public Car {
    public:

        /**
         * @brief Construct a new Ford object
         * 
         * @param name - nazwa mercesa
         * @param fule - typ paliwa
         * @param capacity - pojemnosc
         * @param power - moc
         */

        Ford(std::string fule = "Pb98", int capacity = 1398, int power = 45):
        Car( "Ford Fiesta", fule, capacity, power) {}

};