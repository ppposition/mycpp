#include<iostream>
#include<fstream>
#include"TextQuery.h"
#include"TextQuery.cpp"
using namespace std;

ostream &print(ostream &os,const QueryResult &q){
    os<<q.word<<" occurs "<<q.lines->size()<<((q.lines->size()==1)?string(" time."):string(" times."))<<endl;
    for(auto num:*q.lines)
        os<<"\t(line "<<num+1<<") ";
    return os;
}

void runQueries(ifstream &infile){
    TextQuery tq(infile);
    while(true){
        cout<<"enter word to look for, enter q to quit: ";
        string s;
        if(!(cin>>s)||s=="q")
            break;
        print(cout, tq.query(s))<<endl;
    }
}

int main(){
    ifstream input("test.txt");
    runQueries(input);
    return 0;
}