#include"Animal.h"
#include<cstring>
template<typename T>
Animal<T>::Animal(char n[], T a)
{
    strcpy(name, n);
    age = a;
}

template<typename T>
Animal<T>::~Animal()
{
}

template<typename T>
void Animal<T>::pass_year(){
    age++;
}

template<typename T>
void Animal<T>::self_int() const{
    printf("my name is %s, I am %d years old\n", name, age);
}
