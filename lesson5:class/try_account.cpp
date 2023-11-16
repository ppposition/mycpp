#include<iostream>
#include"Account.h"
#include"Account.cpp"

template<typename U>
void deposit(Account<U>& a, U money){
    a.amount+=money;
}

template<typename U>
void withdraw(Account<U>& a, U money){
    a.amount-=money;
}

int main(){
    Account<double> a1;
    Account<double> a2("jishen", 100);
    cout<<"rate:"<<a1.rate()<<endl;
    a2.change_rate(1.2);
    cout<<"rate:"<<a1.rate()<<endl;
    deposit(a1, 1.0);
    cout<<"a1 has "<<a1.calculate()<<endl;
    return 0;
}