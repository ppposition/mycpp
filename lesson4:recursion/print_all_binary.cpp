#include<iostream>
#include<string>
#include<vector>
using namespace std;
void print(int n, string s){
    if(n==0){
        cout<<s<<endl;
        return;
    }
    print(n-1,"0"+s);
    print(n-1,"1"+s);
}
void dicesum_helper(int dicenum, int num, vector<int> result){
    if(dicenum==0){
        if(num==0){
            for(int i:result)
                cout<<i;
            cout<<endl;
        }
    }
    else{
        for(int i=1;i<=num-dicenum+1;i++){
            result.push_back(i);
            dicesum_helper(dicenum-1, num-i, result);
            result.pop_back();
        }
    }
}

void dicesum(int dicenum, int num){
    vector<int> temp;
    dicesum_helper(dicenum, num, temp);
}

void subset_helper(vector<int> set, vector<int> result){
    if(set.size()==0){
        for(int i:result)
            cout<<i;
        cout<<endl;
    }
    else{
        result.push_back(set[set.size()-1]);
        set.pop_back();
        subset_helper(set, result);
        result.pop_back();
        subset_helper(set, result);
    }
}

void subset(vector<int> set){
    vector<int> temp;
    subset_helper(set, temp);
}

int main(){
    vector<int> v={1,2,3,4};
    subset(v);
    return 0;
}