#include<iostream>
#include"Dog.h"

template<typename T>
Dog<T>::Dog(char n[], T a, T w):Animal<T>(n, a),weight(w){}

template<typename T>
Dog<T>::~Dog()
{
}

template<typename T>
void Dog<T>::burk() const{
    printf("www\n");
}

template<typename T>
void Dog<T>::self_int() const{
    printf("I am a dog, ");
    Animal<T>::self_int();
}