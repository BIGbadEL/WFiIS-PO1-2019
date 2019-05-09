#pragma once

#include <iostream>
#include <string>

class Pomieszczenie {
    public:
        Pomieszczenie(std::string name): _name(name) { std::cout << "Tworze pomieszcznie: " << _name << "\n"; }
        void zetrzyj_kurze() const { std::cout << "Scieram kurze w pomieszczeniu: " << _name << "\n"; }	     // Scieram kurze w pomieszczeniu: kuchnia
        void umyj_podloge() const { std::cout << "Myje podloge w pomieszczeniu: " << _name << "\n"; }	     // Myje podloge w pomieszczeniu: kuchnia
        void odkurz() const { std::cout << "Odkurzam pomieszczenie: " << _name << "\n"; }
        template<typename T>
        void wstaw(T value) const { std::cout << "Wstawiam " << value << " do pomieszczenia: pokoj\n"; }
        const std::string Name() const { return _name; }
    private:
        const std::string _name;
};

template <void (Pomieszczenie::*T)() const >
void Lokaj(Pomieszczenie& room) {
    (room.*T)();
}

template <void (Pomieszczenie::*T)() const >
void Lokaj(const Pomieszczenie& room) {
    std::cout << "Pomieszczenie " << room.Name() << " jest zamknięte.\n";

}

template <int>
void Lokaj(const Pomieszczenie& room) {
    std::cout << "Nic nie robie.\n";
}