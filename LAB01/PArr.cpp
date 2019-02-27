#include "PArr.h"

PArr::~PArr(){
    dtor();
}

void PArr::dtor() {
    for(int i = 0; i < _n; ++i){
        delete _data[i];
    }
    delete[] _data;
}

void PArr::ctor(int n){
    _n = n;
    _data = new Wrapper*[n];
}

PArr& PArr::operator=(const PArr& arr){
    if(&arr == this) return *this;

    dtor();
    ctor(arr._n);

    for(int i = 0; i < _n; ++i){
        _data[i] = arr[i]->nowy();
    }

    return *this;
}

std::ostream& operator<<(std::ostream& stream, const PArr& arr){
    for(int i = 0; i < arr._n; ++i){
        arr[i]->wypisz(stream);
    }

    return stream;
}

