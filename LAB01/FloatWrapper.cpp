#include "FloatWrapper.h"

std::ostream& FloatWrapper::wypisz(std::ostream& stream) const {
    stream << _data << " ";
    return stream;
}

Wrapper* FloatWrapper::nowy() const {
    return new FloatWrapper(*this);
}