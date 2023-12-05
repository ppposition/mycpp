#ifndef _COMPLEX_H
#define _COMPLEX_H
#include<iostream>
#include<cmath>
using namespace std;
template<typename T>
class Complex{
    template<typename U>
    friend istream &operator>>(istream &is, Complex<U> &c);
    template<typename U>
    friend ostream &operator<<(ostream &os, Complex<U> &c);
private:
    T x;
    T y;
public:
    Complex():x(0),y(0){}
    Complex(T x1, T y1):x(x1),y(y1){}
    ~Complex();
    void operator=(const Complex<T> &other);
    Complex<T> operator+(const Complex<T> &other) const;
    void operator+=(const Complex<T> &other);
    Complex<T> operator-(const Complex<T> &other) const;
    void operator-=(const Complex<T> &other);
    bool operator==(const Complex<T> &other) const;
    bool operator!=(const Complex<T> &other) const;
    operator T() const{return sqrt(x*x+y*y);};
};
#endif