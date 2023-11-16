#include<iostream>
using namespace std;
int main(){
    const int c1=10;
    int v1=1, v2=2, v3=3, *pv1=&v3;
    const int *pc1=&v1;
    cout<<(*pc1)<<endl;
    v1 = 3;
    cout<<(*pc1)<<endl;
    pc1 = &v2;
    cout<<(*pc1)<<endl;
    (*pv1)=4;
    cout<<v3<<endl;
    int * const pc2 = &v1;
    *pc2 = 11;
    cout<<v1<<endl;
    return 0;
}