#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;
struct PersonInfo
{
    string name;
    vector<string> phones;
    void intro() const{
        cout<<name<<"has "<<phones.size()<<" phones:";
        for(auto phone:phones)
            cout<<phone<<" ";
        cout<<endl;
    }
};

bool valid(const string &nums){
    return nums.length()==11;
}
int main(int argc, char **argv){
    string line, word;
    vector<PersonInfo> peoples;
    ifstream input("ring.txt");
    while(getline(input, line)){
        PersonInfo info;
        istringstream record(line);
        record>>info.name;
        while(record>>word)
            info.phones.push_back(word);
        peoples.push_back(info);
    }
    for(const auto &people:peoples)
        people.intro();
    for(const auto &people:peoples){
        ostringstream formatted, badNums;
        for(const auto &nums:people.phones){
            if(!valid(nums))
                badNums<<" "<<nums;
            else
                formatted<<" "<<nums;
        }
        if(badNums.str().empty())
            cout<<people.name<<" "<<formatted.str()<<endl;
        else
            cerr<<"input error: "<<people.name<<badNums.str()<<endl;
    }
    return 0;
}