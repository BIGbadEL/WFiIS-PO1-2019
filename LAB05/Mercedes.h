#pragma once
#include "Car.h"

/**
 * @brief kalsa pzowalajaca na wotrzeni samochodow mercedesa bardzij szczegolwy typ Car
 * 
 */

class Mercedes : public Car {
    public:

        /**
         * @brief Construct a new Mercedes object
         * 
         * @param name - nazwa mercesa
         * @param fule - typ paliwa
         * @param capacity - pojemnosc
         * @param power - moc
         */

        Mercedes(std::string gps = "Garmin", std::string name = "Mercedes A", std::string fule = "On", int capacity = 1598, int power = 65):
        Car(gps, name, fule, capacity, power) {}

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

