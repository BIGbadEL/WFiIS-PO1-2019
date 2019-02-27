#pragma once

#include "Wrapper.h"

#include <string>

class StringWrapper : public Wrapper {
    public:

        /**
         * @fn StringWrapper
         * @brief konstruje obiekt StringWrapper
         * 
         * @param [std::string] data -> elemetn ktory chcemy przetrzymywac
         */

        StringWrapper(std::string data): _data(data) { }

        /**
         * @fn wpisz
         * @brief funkcja sluzaca do zwrocenia strumienia wyjscia z danymi obiektu
         * 
         * @param [std::ostream&] stream - strumien wyjscia do ktorego zostana dodane dane obiektu
         * @return std::ostream& - referencja na sturmien wyjscia
         */

        std::ostream& wypisz(std::ostream& stream) const override;

        /**
         * @fn nowy
         * @brief slozy do kopiowania obiektu
         * 
         * @return Wrapper* wskaznik na nowy zalokowny dynamicznie obiekt o tych samych parametrach 
         */

        Wrapper* nowy() const;

    private:
        std::string _data;
};