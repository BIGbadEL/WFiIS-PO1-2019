#pragma once
#include "Compass.h"
#include "Haversine.h"
#include <string>

/**
 * @brief klasa sluzaca do przetrzymywania podstawowych informacji o urzadzeniu gps
 * 
 */

class Gps : public virtual Compass {
public:

    /**
     * @brief Construct a new GPS object
     * 
     * @param model [std::string] -> opisuje model gps
     * @param serial_number [std::string] -> numer seryjny danego urzadzenia
     */

    Gps(std::string name, double lat, double lon): Compass("East"), _model(name), _cordinate(lat, lon) { }  
    
    /**
     * @brief Construct a new Gps object
     * 
     * @param direction - kierunak gps
     */

    Gps(std::string direction): Compass(direction) { }

    /**
     * @brief Construct a new Gps object
     * 
     */

    Gps() = default;

    /**
     * @brief               gets the current GPS location
     * 
     * @return std::string  info of the GPS location
     */

    std::string LocationInfo() const {
        return "Longitude: " +  std::to_string(_cordinate.Longitude()) + " Latitude: " +  std::to_string(_cordinate.Latitude());
    }

    /**
     * @brief zwraca infomacje o kiernku gps
     * 
     * @return std::string - kiernuek gps z infomajca skad pochodzi
     */

    std::string CompassDirection() const override {
            return "G/" + _info;
    }

    /**
     * @brief pozwala na dostep do lokalizaciji gps
     * 
     * @return Coordinate - lokalizacja gps
     */

    Coordinate Location() const {
        return _cordinate; 
    }

    /**
     * @brief aktualizuje pozycje gps
     * 
     * @param coord - nowa pozycja
     */

    void Location(const Coordinate& coord) {
            _cordinate = coord;
    }

    /**
     * @brief pozwala przssunac pozycje gps
     * 
     * @param num - jak dalego chcemy sie przsunac
     * @param direction - w ktora strone
     */

    void Go(double num, std::string direction) {
        _cordinate.MoveInDirection(num, direction);
    }

protected:
    std::string _model;
    Coordinate _cordinate;
};