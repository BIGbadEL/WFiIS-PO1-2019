#pragma once

#include "Engine.h"
#include <vector>

/**
 * @brief ogolna kalsa typu Car
 * 
 */

class Car {

        /**
         * @brief ulatwia wypisywanie obiektu car
         * 
         * @param stream - ref na sturmin wyjsciowy
         * @param car - oboiekt typu car
         * @return std::ostream& ref na sturmien
         */

        friend std::ostream& operator<<(std::ostream& stream, const Car& car);
    public:

        /**
         * @brief Construct a new Car object
         * 
         * @param name - nazwa pojazdu
         * @param fule - typ paliwa
         * @param capacity - pojemnosc silnika
         * @param power - moc silnika
         * @param color - kolor pojzadu - gdy nie posany ustawinay defaltowy
         * @param wheels - ilosc kol
         */

        Car(std::string name, std::string fule, int capacity, int power, std::string color = _color_default)
            : _name(name), _color(color), _engine(fule, capacity, power){
                
            }

        virtual ~Car() = default;

        /**
         * @brief tworzy pojazd zadnaego typu
         * 
         * @param type - typ pojazdu
         * @return Car* - wskaznik na nowo stworzony obiekt
         */

        static Car* Create(std::string type);

        /**
         * @brief pozwala zminic defoultory kolor
         * 
         * @param col - nowy kolor
         */

        static void DefaultColor(std::string col);


    protected:
        std::string _name;
        std::string _color;
        Engine _engine;
        static std::string _color_default;
};

inline std::ostream& operator<<(std::ostream& stream, const Car& car){
    stream << "[INFO] Car:: Type " << car._name << '\n';
    stream << "[INFO] Car:: Color " << car._color << '\n';
    stream << car._engine;
    return stream;
}