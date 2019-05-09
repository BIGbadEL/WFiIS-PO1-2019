#pragma once
#include <iostream>

class ObiektMiotajacy;

class typ {
    public:
        typ() = default;
        virtual void PrzedstawSie() const noexcept = 0;
        virtual ~typ() = default;
        virtual int getID() const  { return 0; };
};

class typ1 : public typ {
    public:
        typ1() = default;
        virtual void PrzedstawSie() const noexcept {
            std::cout << "Nazywam sie 1 (adres obiektu: < " << this << ">)\n" ;
        }
        int getID() const  { return 1; }
};

class typ2 : public typ {
    public:
        typ2() = default;
        void PrzedstawSie() const noexcept {
            std::cout << "Nazywam sie 2 (adres obiektu: < " << this << ">)\n" ;
        }
        int getID() const  { return 2; }
};

class typ3 : public typ {
    public:
        typ3() = default;
        void PrzedstawSie() const noexcept  {
            std::cout << "Nazywam sie 3 (adres obiektu: < " << this << ">)\n" ;
        }
        int getID() const  { return 3; }
};

class typ4 : public typ1 {
    public:
        typ4() = default;
        typ4(const ObiektMiotajacy* obj);
        ~typ4();
        void PrzedstawSie() const noexcept override {
            std::cout << "Nazywam sie 4 (adres obiektu: < " << this << ">)\n" ;
        }
    private:
        const ObiektMiotajacy* _pointer = nullptr;
};

inline void Przetworz(typ* wyj){
    std::cout << "Przetworz - wyjatek typu " << wyj->getID() <<  " o adresie: < " << wyj << " >\n";
    throw;
}
