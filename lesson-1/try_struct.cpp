#include<iostream>
#include<string>
using namespace std;
struct Person{
    int age;
    string name;
    Person():age(0),name("None"){}
    Person(int a,string n):age(a),name(n){}
};
void swap(Person &p1,Person &p2){
    Person p3=p1;
    p1=p2;
    p2=p3;
}
int main(){
    Person p1(21, "position");
    Person p2(22, "purifier");
    cout<<&p1<<endl;
    swap(p1,p2);
    cout<<&p2<<endl;
    cout<<p1.age<<p1.name<<endl;
    return 0;
}