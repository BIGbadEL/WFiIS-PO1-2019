#include "ReadAccess.h"

class ReadWriteAccess {
    public:

        /**
         * @brief konstruje nowy obiekt ReadWriteAccess
         * 
         * @param napis - napis do przechowywania
         */

        ReadWriteAccess(char * napis): _napis(napis) {}

        /**
         * @brief zwraca wskaznik na i-te  slowo
         * 
         * @param i - numer slowa
         * @return char* wskaznik na i-ty wyraz
         */

        char* operator[](int i);
    private:
        char* _napis;
};

