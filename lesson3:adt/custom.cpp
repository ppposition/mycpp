#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<functional>
using namespace std;
using std::placeholders::_1;
bool isShorter(const string &s1, const string &s2){
    return s1.size()<s2.size();
}
bool check_size(const string &s, string::size_type sz){
    return s.size()>=sz;
}

int main(int argc, char **argv){
    vector<string> v;
    ofstream output("some_strings.txt");
    for(int i=0;i<argc;i++){
        v.push_back(argv[i]);
        output<<argv[i]<<endl;
    }

    sort(v.begin(), v.end(),isShorter);
    while(!v.empty()){
        cout<<v.back()<<endl;
        v.pop_back();
    }
    ifstream input("some_strings.txt");
    string temp;
    while(getline(input, temp)){
        v.push_back(temp);
    }
    stable_sort(v.begin(), v.end(),
                [](const string &s1, const string &s2){return s1.length()<s2.length();});
    for(auto itor=v.begin();itor!=v.end();itor++)
        cout<<*itor<<endl;
    int sz=8;
    auto wc = find_if(v.begin(), v.end(), [sz](const string &s1){return s1.size()>=sz;});
    cout<<v.end()-wc<<" words is longer than "<<sz<<endl;
    auto wc2 = find_if(v.begin(), v.end(), bind(check_size, _1, sz));
    for_each(wc2, v.end(), [](const string &s){cout<<s<<" "<<endl;});
    return 0;
}