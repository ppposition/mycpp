#include<iostream>
#include"Account.h"
using namespace std;

template<typename T>
T Account<T>::interestRate=1.1;

template<typename T>
Account<T>::Account(string name, T a)
{
    owner = name;
    amount = a;
}

template<typename T>
Account<T>::~Account()
{
}

template<typename T>
T Account<T>::rate(){
    return interestRate;
}

template<typename T>
void Account<T>::change_rate(T new_rate){
    interestRate = new_rate;
}

template<typename T>
T Account<T>::calculate() const{
    return amount*interestRate;
}