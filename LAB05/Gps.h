#pragma once

#include <string>

/**
 * @brief klasa sluzaca do przetrzymywania podstawowych informacji o urzadzeniu gps
 * 
 */

class GPS {
public:

    /**
     * @brief Construct a new GPS object
     * 
     * @param model [std::string] -> opisuje model gps
     * @param serial_number [std::string] -> numer seryjny danego urzadzenia
     */

    GPS(std::string model, std::string serial_number = "No.000.000"): _model(model), _serialNumber(serial_number) { }

    /**
     * @brief Get the Specification object
     * 
     * @return std::string cala specyfikacja dangeo urzadzenia
     */

    std::string getSpecification() const {
        return _model + "/" + _serialNumber;
    }

private:
    std::string _model;
    std::string _serialNumber;
};