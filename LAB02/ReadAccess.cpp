#include "ReadAccess.h"
#include <cstring>

int find_word(const std::string napis, int index){
    if(index == 0) return 0;
    size_t offset = 0;
    int spaces = 0;
    while(spaces != index){
        offset++;
        if(offset >= napis.size()) return -1;
        if(napis[offset] == ' ')
            spaces++;
    }
    return offset + 1;
}

ReadAccess::ReadAccess(const char* napis): _napis(napis){ }

const std::string ReadAccess::operator[](int i) const {
    int offset = find_word(_napis, i);
    if(offset == -1) return "\0";
    return _napis.c_str() + offset;
}