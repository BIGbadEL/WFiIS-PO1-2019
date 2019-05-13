#pragma once

#include <iostream>
#include <string>

class Engine {

        /**
         * @brief przeladowanie operatora sturminia sluzace do ulatwina wypisawania obiektow typu engine
         * 
         * @param stream - referencja na strumien
         * @param eng - obiekt do wypisnia
         * @return std::ostream& - zwracana referencja na strumien
         */

        friend std::ostream& operator<<(std::ostream& stream, const Engine& eng);
    public:

        /**
         * @brief Construct a new Engine object
         * 
         * @param fule - typ paliwa
         * @param capacity - pojemnosc silnika
         * @param power - moc silnika
         */

        Engine(std::string fule, int capacity, int power):
            _fule(fule), _capacity(capacity), _power(power) {}
    private:
        std::string _fule;
        int _capacity;
        int _power;
};

inline std::ostream& operator<<(std::ostream& stream, const Engine& eng){
    stream << "[INFO] Engine:: Fluel " << eng._fule << '\n';
    stream << "[INFO] Engine:: Capacity " <<  eng._power << " [cm^3]" << '\n';
    stream << "[INFO] Engine:: Power " << eng._capacity << " [kW]";
    return stream;
}