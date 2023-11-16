#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include<iostream>
using namespace std;
template<typename T>
class Account
{
    template<typename U>
    friend void deposit(Account<U>&, U);
    template<typename U>
    friend void withdraw(Account<U>&, U);
private:
    string owner="nation";
    T amount=0.0;
    static T interestRate;
public:
    Account()=default;
    Account(string name, T a);
    ~Account();
    static T rate();
    static void change_rate(T);
    T calculate() const;
};

#endif 

