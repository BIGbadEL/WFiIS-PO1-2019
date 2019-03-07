#pragma once

#include "ReadAccess.h"
#include "ReadWriteAccess.h"

class WordAccess {
    public:

        /**
         * @brief sprawdza czy jestesmy poza napisem
         * 
         * @param wyraz - aktualny wyraz
         * @return true - jesli jetesmy poza
         * @return false - gdy dalej jestesmy w napisise
         */

        static bool eofSentence(std::string wyraz){
            return wyraz[0] == '\0';
        }

        /**
         * @brief sprawdza czy jestesmmy na koncu slowa
         * 
         * @param znak - w slowie
         * @return true - jesli slowo sie skonczylo
         * @return false - znak nie jest ostatim znakie w slowie
         */

        static bool eofWord(char znak){
            return znak == ' ' || znak == '\0';
        }
};