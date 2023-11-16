#include<iostream>
using namespace std;
int main(int argc, char **argv){
    string ans="";
    for(int i=0;i<argc;i++){
        cout<<argv[i]<<endl;
        ans += argv[i];
    }
    cout<<ans<<endl;
    return 0;
}