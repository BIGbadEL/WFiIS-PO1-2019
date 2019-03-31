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

        Ford(std::string gpsFirm = "Google", std::string name = "Ford Fiesta", std::string fule = "Pb98", int capacity = 1398, int power = 45):
        Car(gpsFirm, name, fule, capacity, power) {}

        /**
         * @brief funkcja sluzaca do dostania sie do informacji o modelu gps w Fordzie
         * 
         * @return std::string infomacje o GPS
         */

        std::string GpsInfo() const override {
            std::string temp(_name.cbegin(), _name.cbegin() + 1);
            return temp + "/" + _gps.getSpecification() + "\n";
        }
};