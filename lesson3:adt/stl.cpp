#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<int>> a={{1,2,3,4,5}};
    stack<int> s;
    queue<int> q;
    unordered_set<int> my_set, set2, merge_set;

    for(vector<int> v:a){
        cout<<v[0]<<endl;
        v.emplace(v.begin()+1, 3);
        for(int i:v)
            s.push(i);
    }
    while(!s.empty()){
        cout<<s.top();
        q.push(s.top());
        s.pop();
    }
    cout<<endl;
    while (!q.empty())
    {
        cout<<q.front();
        my_set.emplace(q.front());
        q.pop();
    }
    cout<<endl;
    cout<<"the size of the set is: "<<my_set.size()<<endl;
    for(int i=3;i<7;i++)
        set2.emplace(i);
    set_union(my_set.begin(), my_set.end(), set2.begin(), set2.end(), inserter(merge_set, merge_set.begin()));
    cout<<merge_set.size()<<endl;
    for(int i:merge_set)
        cout<<i;
    cout<<endl;
    if(my_set.find(3)!=my_set.end())
        cout<<"find 3";
    return 0;
}