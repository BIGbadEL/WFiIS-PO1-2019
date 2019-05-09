#include "Compass.h"


class TrackingSystem : public virtual Compass {
    public:
        /**
         * @brief Construct a new Tracking System object
         * 
         */
        TrackingSystem(): Compass("North") {}

        /**
         * @brief Construct a new Tracking System object
         * 
         * @param direction  - kierunek tracikng systemu
         */

        TrackingSystem(std::string direction): Compass(direction) { }

        /**
         * @brief zwraca infomacje o kienrku tracking systemu
         * 
         * @return std::string kiernik tracking systemu warz z inforacja z jaakiej pochodzi kalsy
         */

        std::string CompassDirection() const override {
            return "T/" + _info;
        }
};