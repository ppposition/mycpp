#ifndef _HASH_H
#define _HASH_H
#include<iostream>
#include<string>
using namespace std;
const int HASH_SEED = 5381;
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1)>>1;
class hash{
private:
    int capacity;
    string **buckets;
    int hashCode(const string &str){
        unsigned hash = HASH_SEED;
        for(int i=0;i<str.length();i++)
            hash += str[i];
        return int(hash & HASH_MASK);
    }
public:
    hash(int c);
    ~hash();
    void insert(string s);
    void contain(string s);
    void remove(string s);
};
#endif _HASH_H