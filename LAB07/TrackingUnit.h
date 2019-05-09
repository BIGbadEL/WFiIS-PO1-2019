#pragma once

#include "Gps.h"
#include "TrackingSystem.h"

class TrackingUnit : public Gps, public TrackingSystem {
    public:
        /**
         * @brief Construct a new Tracking Unit object
         * 
         */

        TrackingUnit(): Compass("South") {}

        /**
         * @brief zwraca infomacje o kienrku tracking unit
         * 
         * @return std::string kiernik tracking unit warz z inforacja z jaakiej pochodzi kalsy
         */

        std::string CompassDirection() const override {
            return "TUnit/" + _info;
        }

        /**
         * @brief zpaisuje aktualna pozycja jako pozcyje startowa
         * 
         */

        void Start() {
            _startPoint = _cordinate;
        }

        /**
         * @brief oblicza dystans mieszy pozycja startowa a aktualna
         * 
         * @return double - dystans
         */

    double Distance() const {
        return ::Distance(_startPoint, _cordinate).Value();
    }

    protected:  
        Coordinate _startPoint;

};