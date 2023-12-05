#include<iostream>
#include<functional>
using namespace std;
struct myFunction
{
    int times;
    int operator()(int val) const{
        return times*val;
    }
    myFunction(int t){
        times = t;
    }
};

int add(int i,int j){return i+j;}
int main(){
    myFunction f(10);
    function<int(int, int)> f1=add;
    function<int(int)> f2=f;
    function<int(int, int)> f3=[](int i,int j){return i/j;};
    cout<<f1(4,2)<<endl;
    cout<<f2(4)<<endl;
    cout<<f3(4,2)<<endl;
    return 0;
}