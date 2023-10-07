#include<iostream>
#include"CuckooHash.h"
#include"CuckooHash.cpp"
using namespace std;
int main(){
    CuckooHash ch(5);
    ch.insert(4);
    ch.insert(9);
    if(ch.contain(9))
        cout<<"success"<<endl;
    ch.insert(14);
    if(ch.contain(4))
        cout<<"confuse"<<endl;
    return 0;
}