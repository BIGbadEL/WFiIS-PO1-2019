#include "IntWrapper.h"

std::ostream& IntWrapper::wypisz(std::ostream& stream) const {
    stream << _data << " ";
    return stream;
}

Wrapper* IntWrapper::nowy() const {
    return new IntWrapper(*this);
}