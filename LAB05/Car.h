#pragma once

#include "Engine.h"
#include "Wheel.h"
#include "Gps.h"
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

        Car(std::string _gpsFirm, std::string name, std::string fule, int capacity, int power, std::string color = _color_default, int wheels = 4)
            : _gps(_gpsFirm), _name(name), _color(color), _engine(fule, capacity, power), _wheels(wheels){
                
            }

        virtual ~Car() = default;

        /**
         * @brief zwraca pojemnik z kolami pojazdu
         * 
         * @return const std::vector<Wheel*>& 
         */

        const std::vector<Wheel*>& WheelsVector() const {
            return _wheels.get();
        }

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

        /**
         * @brief zezwala na dostep do whhelTab w ktorym sa kola pojazdu
         * 
         * @return const WheelTab* 
         */

        const WheelTab* Wheels() const {
            return &_wheels;
        }

        /**
         * @brief funkcja wirtualna sluzaca do wypisywnai informacji o gps W SPECYFICZNYM samochodzie
         * 
         * @return std::string - infomacje o gps w danym samochodzie (zawira infomacje o firmie samochodu)
         */

        virtual std::string GpsInfo() const = 0;

    protected:
        GPS _gps;
        std::string _name;
        std::string _color;
        Engine _engine;
        WheelTab _wheels;
        static std::string _color_default;
};

inline std::ostream& operator<<(std::ostream& stream, const Car& car){
    stream << "[INFO] Car:: Type " << car._name << '\n';
    stream << "[INFO] Car:: Color " << car._color << '\n';
    stream << car._engine;
    return stream;
}