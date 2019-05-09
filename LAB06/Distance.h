#pragma once
#include <cmath>
#include "Haversine.h"

class Distance {
    public:

        /**
         * @brief konstruktor dla klasy Distance wyliczajacy Haversine z podanych argumentow
         *    
         * @param x1
         * @param y1
         * @param x2
         * @param y2
         */
        Distance(float x1, float y1, float x2, float y2)
        : _val(Haversine(x1, y1, x2, y2)) {  }


        /**
         * @brief konstruktor dla klasy Distance wyliczajacy Haversine z podanych argumentow
         * 
         * @param Coordinate& p1    pierwszy punkt
         * @param Coordinate& p2    drugi punkt
         */
        Distance(const Coordinate& p1, const Coordinate& p2)
        : Distance( p1.Longitude(), p1.Latitude(), p2.Longitude(), p2.Latitude()) {    }


        /**
         * @brief           funkcja getter dla _val
         * 
         * @return double   odleglosc
         */
        double Value() const {
            return _val;
        }

    private:
        double _val;
};