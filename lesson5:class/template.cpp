#include<iostream>
using namespace std;
template<typename T>
class a_test
{
private:
    T num[10];
    int top;
public:
    a_test(/* args */){
        top=-1;
    };
    ~a_test(){

    };
    void push(T a){
        num[++top]=a;
    }
    T pop(){
        return num[top--];
    }
};

int main(){
    a_test<int> s;
    for(int i=0;i<5;i++)
        s.push(i);
    for(int i=0;i<5;i++)
        printf("%d",s.pop());
    return 0;
}

