#include "StringWrapper.h"

std::ostream& StringWrapper::wypisz(std::ostream& stream) const {
    stream << _data << " ";
    return stream;
}

Wrapper* StringWrapper::nowy() const {
    return new StringWrapper(*this);
}