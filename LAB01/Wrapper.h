#pragma once

#include <iostream>

/**
 * @class Wrapper
 * @brief kalsa abstrkacyjna sluzaca jako wrapper na odpowiednie typy 
 * 
 */

class Wrapper {
    public:

        /**
         * @fn wpisz
         * @brief funkcja sluzaca do zwrocenia strumienia wyjscia z danymi obiektu
         * 
         * @param [std::ostream&] stream - strumien wyjscia do ktorego zostana dodane dane obiektu
         * @return std::ostream& - referencja na sturmien wyjscia
         */

        virtual std::ostream& wypisz(std::ostream& stream) const = 0;

        /**
         * @fn ~Wrapper
         * @brief Niszczy obiekt
         * 
         */

        virtual ~Wrapper() = default;

        /**
         * @fn nowy
         * @brief slozy do kopiowania obiektu
         * 
         * @return Wrapper* wskaznik na nowy zalokowny dynamicznie obiekt o tych samych parametrach 
         */

        virtual Wrapper* nowy() const = 0;
};