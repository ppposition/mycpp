#include<iostream>
#include"Hash.h"
#include"Hash.cpp"
using namespace std;
int main(){
    Hash myhash(13);
    myhash.insert("jsjsjs");
    if(myhash.contain("jsjsjs"))
        cout<<"success"<<endl;
    myhash.rehash(17);
    cout<<"rehash finished"<<endl;
    return 0;
}