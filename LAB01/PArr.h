#pragma once

#include <iostream>

#include "Wrapper.h"

class PArr {

        /**
         * @fn operator<<
         * @brief pozwala wypszac obiekt PArr na ekran
         * 
         * @param [std::ostream&] -> stream strumien wyjscia
         * @param [const PArr&] arr -> obket do wypisania 
         * @return std::ostream& -> referencja na sturmien
         */

        friend std::ostream& operator<<(std::ostream& stream, const PArr& arr);
    public:

        /**
         * @fn PArr
         * @brief Konstuktor klasy PArr
         * 
         * @param [int] n -> ilosc lementow ktore bedzie przetrzymawac obiekt
         */

        PArr(int n){ ctor(n); }

        /**
         * @fn ~PArr
         * @brief Niszczy obietk PArr zapewnia zarzadzanie pamiecia
         * 
         */

        ~PArr();

        /**
         * @fn operator=
         * @brief operoator przypisana klasy PArr
         * 
         * @param arr obketk ktory chcemy przpisac
         * @return PArr& 
         */

        PArr& operator=(const PArr& arr);

        /**
         * @fn operator@
         * @brief pozwala na dostep do obiektu
         * 
         * @param n -> index elementu
         * @return Wrapper*& referencja na element
         */

        Wrapper*& operator[](int n) const { return _data[n]; }
    private:
        void dtor();
        void ctor(int n);
    private:
        int _n;
        Wrapper** _data;
};


