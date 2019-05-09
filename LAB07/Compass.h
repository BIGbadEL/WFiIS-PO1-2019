#pragma once
#include <string>

/**
 * @brief klasa Compass pozwalajca na przetrzymwanie jednego z 4 kierunkow
 * 
 */

class Compass {
    public:
        /**
        * @brief Construct a new Compass object
        * 
        */

        Compass(): _info("West") {}

        /**
         * @brief Construct a new Compass object
         * 
         * @param kierunek - kierunek 
         */

        Compass(std::string kierunek): _info(kierunek) { }

        /**
         * @brief zwraca informacje o kierunku kompasu
         * 
         * @return std::string - kierunek z informacja z jakiej klasy pochodzi
         */

        virtual std::string CompassDirection() const {
            return "C/" + _info;
        }

        /**
         * @brief zwraca string odpowiadujacemu kierunkowi North
         * 
         * @return std::string 
         */

        static std::string North() {
            return "North";
        }

        /**
         * @brief Destroy the Compass object
         * 
         */

        virtual ~Compass() = default;

    protected:
        std::string _info; /**< informacja o kierunku swiata */
};