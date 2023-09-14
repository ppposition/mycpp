#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<"give me your name:";
    string name;
    getline(cin, name);
    cout<<"Hello,"<<name+"lalala"<<endl;
    return 0;
}