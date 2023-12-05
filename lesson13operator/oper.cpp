#include<iostream>
#include"Complex.h"
#include"Complex.cpp"
using namespace std;
int main(){
    Complex<double> c1(1.5, 2.5);
    Complex<double> c2;
    cin>>c2;
    Complex<double> c3 = c1 + c2;
    cout<<c3<<endl;
    cout<<static_cast<double>(c3)<<endl;
    return 0;   
}