#include<iostream>
#include"TVec.h"
#include"TVec.cpp"
using namespace std;
int main(){
    TVec<int> t;
    for(size_t i=0;i<10;i++)
        t.push_back(i);
    cout<<"size of t:"<<t.size()<<", capacity of t:"<<t.capacity()<<endl;
    TVec<int> t_copy=t;
    cout<<"size of t_copy:"<<t.size()<<", capacity of t_copy:"<<t_copy.capacity()<<endl;
    cout<<t[0]<<endl;
}