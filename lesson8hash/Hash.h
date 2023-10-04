#ifndef _HASH_H
#define _HASH_H
#include<iostream>
#include<string>
using namespace std;
const int HASH_SEED = 5381;
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1)>>1;
struct Cell
{
    string name;
    Cell *next;
    Cell(string n):name(n){}
};

class Hash{
private:
    int capacity;
    Cell **buckets;
    int hashCode(const string &str){
        unsigned hash = HASH_SEED;
        for(int i=0;i<str.length();i++)
            hash += str[i];
        return int(hash & HASH_MASK);
    }
public:
    Hash(int c);
    ~Hash();
    void insert(string s);
    bool contain(string s);
    void remove(string s);
    void rehash(int c);
};
#endif _HASH_H