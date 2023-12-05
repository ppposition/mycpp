#include"Complex.h"

template<typename T>
Complex<T>::~Complex(){
}

template<typename T>
void Complex<T>::operator=(const Complex &other){
    this->x=other.x;
    this->x=other.y;
}

template<typename T>
Complex<T> Complex<T>::operator+(const Complex<T> &other) const{
    return Complex<T>(this->x+other.x,this->y+other.y);
}

template<typename T>
void Complex<T>::operator+=(const Complex &other){
    this->x += other.x;
    this->y += other.y;
}

template<typename T>
Complex<T> Complex<T>::operator-(const Complex<T> &other) const{
    return Complex<T>(this.x-other.x,this->y-other.y);
}

template<typename T>
void Complex<T>::operator-=(const Complex &other){
    this->x -= other.x;
    this->y -= other.y;
}

template<typename T>
bool Complex<T>::operator==(const Complex &other) const{
    return (this->x==other.x)&&(this->y==other.y);
}

template<typename T>
bool Complex<T>::operator!=(const Complex<T> &other) const{
    return !(*this==other);
}

template<typename U>
istream &operator>>(istream &is, Complex<U> &c){
    is>>c.x>>c.y;
    return is;
}

template<typename U>
ostream &operator<<(ostream &os, Complex<U> &c){
    if(c.y==0)
        os<<c.x;
    else if(c.x==0)
        os<<c.y<<"i";
    else
        os<<c.x<<"+"<<c.y<<"i";
    return os;
}