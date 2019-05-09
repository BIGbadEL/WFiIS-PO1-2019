#pragma once
#include "typy.h"

class ObiektMiotajacy {
    public:
        void Rzuc() const  { 
            throw new typ4{this};
        }
};
