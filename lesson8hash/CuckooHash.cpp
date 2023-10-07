#include"CuckooHash.h"
#include<iostream>
using namespace std;
CuckooHash::CuckooHash(int c)
{
    capacity = c;
    bucket1 = new int [c];
    bucket2 = new int [c];
}

CuckooHash::~CuckooHash()
{
    delete bucket1;
    delete bucket2;
}

bool CuckooHash::contain(int v){
    return (v == bucket1[h1(v)]) || (v == bucket2[h2(v)]);
}

void CuckooHash::insert(int v){
    if(contain(v))
        return;
    insert_helper(v, 0, 0);
}

void CuckooHash::insert_helper(int v, int table_num, int time){
    if(time>=2){
        cout<<"cannot insert, kick off"<<v<<endl;
        return;
    }
    if(table_num==0){
        size_t hash1 = h1(v);
        if(bucket1[hash1]==0){
            bucket1[hash1]=v;
            return;
        }
        else{
            int temp = bucket1[hash1];
            bucket1[hash1]=v;
            insert_helper(temp, 1-table_num, time+1);
        }
    }
    else{
        size_t hash2 = h2(v);
        if(bucket2[hash2]==0){
            bucket2[hash2]=v;
            return;
        }
        else{
            int temp = bucket2[hash2];
            bucket2[hash2]=v;
            insert_helper(temp, 1-table_num, time+1);
        }
    }
}

void CuckooHash::remove(int v){
    if(bucket1[h1(v)]==v)
        bucket1[h1(v)]=0;
    else
        bucket2[h2(v)]=0;
}