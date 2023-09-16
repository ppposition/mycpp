#include "Reset.h"
#include <iostream>

template<typename T>
Reset<T>::Reset() {}

template<typename T>
Reset<T>::Reset(std::string n, T v) : name(n), value(v) {}

template<typename T>
void Reset<T>::print() const {
    std::cout << "Name: " << name << ", Value: " << value << std::endl;
}

template<typename T>
bool Reset<T>::operator<(const Reset& other) {
    return value < other.value;
}
