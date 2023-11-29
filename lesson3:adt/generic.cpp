#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main(int argc, char **argv){
    int val;
    vector<int> a;
    for(int i=1;i<argc;i++)
        a.push_back(stoi(argv[i]));
    while(cin>>val){
        if(val==-1)
            break;
        auto result=find(a.cbegin(), a.cend(), val);
        cout<<"The value "<<val<<(result==a.cend()?" is not present":" is present")<<endl;
    }
    cout<<"the sum is "<<accumulate(a.cbegin(), a.cend(), 0)<<endl;
    fill(a.begin(),a.begin()+3*a.size()/4,1);
    cout<<"the elements of the vector have been changed"<<endl;
    while(cin>>val){
        if(val==-1)
            break;
        auto result=find(a.cbegin(), a.cend(), val);
        cout<<"The value "<<val<<(result==a.cend()?" is not present":" is present")<<endl;
    }
    cout<<"the sum is "<<accumulate(a.cbegin(), a.cend(), 0)<<endl;
    return 0;
}