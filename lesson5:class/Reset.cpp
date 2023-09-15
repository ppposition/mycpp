#include<iostream>
#include"Reset.h"
using namespace std;
template<typename T>
void Reset<T>::print(){
    cout<<"name:"<<name<<",value:"<<value<<endl;
}