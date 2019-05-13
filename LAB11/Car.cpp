#include "Car.h"

#include "Mercedes.h"
#include "Ford.h"

std::string Car::_color_default = "Red";

Car* Car::Create(std::string type){
    if( type == "Mercedes" ){
        return new Mercedes{};
    } else {
        return new Ford{};
    }

}

void Car::DefaultColor(std::string col){
    _color_default = col;
}