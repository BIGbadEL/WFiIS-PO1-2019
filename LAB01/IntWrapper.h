#pragma once

#include "Wrapper.h"

class IntWrapper : public Wrapper {
    public:

        /**
         * @fn IntWrapper
         * @brief konstruje obiekt IntWrapper
         * 
         * @param [int] data -> elemetn ktory chcemy przetrzymywac
         */

        IntWrapper(int data): Wrapper(), _data(data) {}

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
        int _data;
};