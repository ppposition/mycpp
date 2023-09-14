#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.first==p2.first)
        return p1.second<p2.second;
    return p1.first<p2.first;
}
// 数飞机，即给出各架飞机的起飞和降落时间，求出在同一时间内在天上的飞机的数量的最大值
int scan_count(vector<pair<int,int>> planes){
    int ans=0;
    int cur=0;
    vector<pair<int,int>> times;
    for(auto plane:planes){
        times.push_back({plane.first,1});
        times.push_back({plane.second,-1});
    }
    sort(times.begin(),times.end(),cmp);
    for(auto time:times){
        cur+=time.second;
        ans=max(cur,ans);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> planes;
    for(int i=0;i<n;i++){
        int takeoff, land;
        cin>>takeoff>>land;
        planes.push_back({takeoff,land});
    }
    cout<<scan_count(planes);
    return 0;
}