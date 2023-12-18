#include<iostream>
#include<fstream>
#include"Query.h"
#include"TextQuery.h"
#include"TextQuery.cpp"
using namespace std;
ostream &operator<<(ostream &os,const Query &query){
    return os<<query.rep();
}
ostream &print(ostream &os, const QueryResult &q){
    os<<q.word<<" occurs "<<q.lines->size()<<((q.lines->size()==1)?string(" time"):string(" times"))<<endl;
    for(auto num:*q.lines)
        os<<"\t(line "<<num+1<<") "<<(*q.file)[num]<<endl; 
    return os;
}
void runQueries(ifstream &infile, const string &s1, const string &s2){
    TextQuery tq(infile);
    Query q1(s1),q2(s2);
    Query q3 = q1 & q2;
    print(cout, q3.eval(tq));
}
int main(){
    ifstream input("test.txt");
    runQueries(input, "position","lay");
    return 0;
}