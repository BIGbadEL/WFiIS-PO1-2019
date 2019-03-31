#pragma once
#include <vector>
#include <iostream>

/**
 * @brief klasa reprezuntujaca kolo
 * 
 */

class Wheel {
    public:
        /**
         * @brief pozwal na dostp do infomacji o cisnieu w kole
         * 
         * @return double 
         */
        double Pressure() const { return _pressure; }
    private:
        double _pressure = 2.2;
};

/**
 * @brief pojemnik na kola
 * 
 */

class WheelTab{
    public:

        /**
         * @brief Construct a new Wheel Tab object
         * 
         * @param x - ilosc kol
         */

        WheelTab(int x){
            for(int i = 0; i < x; i++){
                _wh.push_back( new Wheel());
            }
        }

        /**
         * @brief Destroy the Wheel Tab object
         * 
         */

        ~WheelTab(){
            for(auto el : _wh){
                delete el;
            }
        }

        /**
         * @brief pozwal na dostep do vektora w krorym sa kola
         * 
         * @return const std::vector<Wheel*>& 
         */

        const std::vector<Wheel*>& get() const {
            return _wh;
        }

        /**
         * @brief wypisuje infomacji o cisnieniu w kazdym kole
         * 
         */

        void PressureInfo() const {
            int i = 0;
            for(auto el : _wh){
                std::cout << "[INFO] :: Wheel [" << i << "] :: Pressure " << el->Pressure() << " [bar]" << '\n';
            }
        }
    private:
        std::vector<Wheel*> _wh;
};