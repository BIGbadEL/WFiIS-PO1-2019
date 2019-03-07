#include "ReadWriteAccess.h"

char* ReadWriteAccess::operator[](int i){
    int offset = find_word(_napis, i);
    return _napis + offset;
}