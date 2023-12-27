#include<iostream>
using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t){
    return os<<t<<endl;
}

template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest){
    os<<t<<" ";
    return print(os, rest...);
}

template<>
ostream &print(ostream &os, const int &i){
    return os<<"i="<<i<<endl;
}

int main(){
    int i = 1;
    string s = "ssss";
    print(cout, i, s, 2);
    print(cout, 2, i, s);
    return 0;
}