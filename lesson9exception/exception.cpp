#include<iostream>
using namespace std;
int main(){
    try
    {
        int a,b;
        cin>>a>>b;
        if(a!=b)
            throw runtime_error("must be same");
    }
    catch(exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}