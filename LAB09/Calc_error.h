#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

/**
 * @class Calc_error 
 * @brief klasa wyjatku sluzaca do obslugi bledow obliiczniach
 * 
 */

class Calc_error : public std::runtime_error {
    public:

        /**
         * @brief Construct a new Calc_error object
         * 
         * @param err -> wskazniik na wyjatek ktory pojaiwl sie wczesniej
         * @param info -> informacje o powodzie pojaienia sie wyjatku
         * @param file -> nazwa pliku w ktorym wyjatek sie pojaiwl
         * @param line -> linia w ktorej wyjatek zostal rzucony
         */

        Calc_error( std::runtime_error* err, std::string info, std::string file, int line)
            :  std::runtime_error(info + ", " + "[plik = " + file + ", " + "linia = " + std::to_string(line) + "]")
            {
                _wczesniejsze.push_back(err);
            }

        /**
         * @brief funkcja statyczna obslugujaca wyjatki klasy calc_error ktore pojaily sie do tej pory
         * 
         */
        
        static void handler() {
            std::cout << " Zlapano wyjatek: \n";

            try {
                throw;
            } catch(std::runtime_error* e) {
                std::cout << "-- z powodu: " << e->what() << "\n";
                delete e;
            }

            while(!_wczesniejsze.empty()){
                std::cout << "-- z powodu: " << _wczesniejsze.back()->what() << "\n";
                delete _wczesniejsze.back();
                _wczesniejsze.pop_back();
            }
        }

    private:
        static std::vector<std::runtime_error*> _wczesniejsze; /**< statyczny wektor zbierajacy informacje o wyjatkach ktore pojaily sie wczesniej*/
};