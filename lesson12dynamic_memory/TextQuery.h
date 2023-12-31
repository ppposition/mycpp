#ifndef _TEXTQUERY_H
#define _TEXTQUERY_H

#include<iostream>
#include<memory>
#include<vector>
#include<set>
#include<map>
using namespace std;
using line_no = vector<string>::size_type;

class QueryResult{
friend ostream &print(ostream &os,const QueryResult &q);
public:
    QueryResult(string w, shared_ptr<set<line_no>> l, shared_ptr<vector<string>> f):
    word(w),lines(l),file(f){}
    set<line_no>::iterator begin() const{return lines->begin();}
    set<line_no>::iterator end() const{return lines->end();}
    shared_ptr<vector<string>> get_file() const{return file;}
private:
    string word;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

class TextQuery
{
private:
    /* data */
    shared_ptr<vector<string>> file;
    map<string,shared_ptr<set<line_no>>> wm;
public:
    TextQuery(ifstream&);
    QueryResult query(const string &) const;
    ~TextQuery();
};

#endif