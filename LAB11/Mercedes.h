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

        Mercedes(std::string fule = "On", int capacity = 1598, int power = 65):
            Car("Mercedes", fule, capacity, power) {}



};

