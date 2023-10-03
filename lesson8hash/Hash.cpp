#include"Hash.h"
Hash::Hash(int c){
    capacity = c;
    buckets = new Cell * [c];
    for(int i=0;i<c;i++){
        buckets[i] = nullptr;
    }
}

Hash::~Hash(){
    for(int i=0;i<capacity;i++){
        Cell *temp=buckets[i];
        while(temp!=nullptr){
            Cell *current = temp;
            temp = temp->next;
            delete temp;
        }
    }
}

void Hash::insert(string s){
    int position = hashCode(s)%capacity;
    Cell *temp = new Cell(s);
    temp->next = buckets[position];
    buckets[position] = temp;
}

bool Hash::contain(string s){
    int position = hashCode(s)%capacity;
    Cell *
}