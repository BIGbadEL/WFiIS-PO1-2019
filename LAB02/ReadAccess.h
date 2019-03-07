#pragma once
#include <string>

/**
 * @brief zwraca offset/index od ktorego zaczna sie slowao o indeksie
 * 
 * @param napis - napis ktory przeszukuejy
 * @param index - numer slowa
 * @return int - offset
 */

int find_word(std::string napis, int index);

class ReadAccess {
    public:

        /**
         * @brief Konstruje nowy obiekt Read Access
         * 
         * @param napis napis ktrory bedzie przechowywany
         */

        ReadAccess(const char* napis);

        /**
         * @brief pozwala na dostep do slowa
         * 
         * @param i - index slowa
         * @return const std::string - slowa zwracane
         */

        const std::string operator[](int i) const;

    private:
        std::string _napis;
        int _spaces;
};