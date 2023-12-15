#include<iostream>
#include"Animal.h"
#include"Animal.cpp"
#include"Dog.h"
#include"Dog.cpp"
using namespace std;
int main(){
    Animal<int> a("jz",10);
    Dog<int> d("wkz", 10, 60);
    a.self_int();
    d.self_int();
    Animal<int> *c = new Dog<int>("wkz", 10, 50);
    c->self_int();
    return 0;
}