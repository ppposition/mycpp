#ifndef _CUCKOOHASH_H
#define _CUCKOOHASH_H
#include<iostream>
class CuckooHash
{
private:
    int capacity;
    int *bucket1;
    int *bucket2;
    size_t h1(int value){
        return value%capacity;
    }
    size_t h2(int value){
        return (value+2)%capacity;
    }
    void insert_helper(int v, int table_num, int time);
public:
    CuckooHash(int c);
    ~CuckooHash();
    bool contain(int v);
    void insert(int v);
    void remove(int v);
};
#endif

