#include "MyReset.h"
#include <iostream>

template<typename T>
MyReset<T>::MyReset():name("noname"),value(0){}

template<typename T>
MyReset<T>::MyReset(std::string n, T v) : name(n), value(v) {}

template<typename T>
void MyReset<T>::print() const {
    std::cout << "Name: " << name << ", Value: " << value << std::endl;
}

template<typename T>
bool MyReset<T>::operator<(const MyReset& other) const{
    return this->value < other.value;
}
