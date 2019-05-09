#pragma once
#include <iostream>
#include "Calc_error.h"

/**
 * @class LicznikPoziomow
 * @brief klasa sluzaca do oblicznia aktualnego poziomu
 * 
 */

class LicznikPoziomow {
    public:

        /**
         * @brief Konstruktor wypisujacy informacje o akutalnym poziomie
         * 
         */

        LicznikPoziomow(){
            counter++;
            std::cout << "Rozpoczynamy poziom numer " << counter << ".\n";
        }

        /**
         * @brief Destruktor wyisujacy informacje o konczeniu poziomu
         * 
         */

        ~LicznikPoziomow(){
            std::cout << "Konczymy poziom numer" << counter << ".\n";
            counter--;
        }

    private:
        static int counter; /**< statyczny licznik poziomow*/
};