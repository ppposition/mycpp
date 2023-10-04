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
    Cell *temp = buckets[position];
    while(temp!=nullptr){
        if(temp->name==s)
            return true;
        temp = temp->next;
    }
    return false;
}

void Hash::remove(string s){
    int position = hashCode(s)%capacity;
    Cell *temp = buckets[position];
    if(temp==nullptr){
        cout<<s<<" does not exist"<<endl;
    }
    else if(temp->name==s){
        buckets[position] = temp->next;
        delete temp;
    }
    else{
        while(temp->next!=nullptr){
            if(temp->next->name==s){
                Cell *current = temp->next;
                temp->next = temp->next->next;
                delete current;
                return;
            }
            temp = temp->next;
        }
        cout<<s<<" does not exist"<<endl;
    }
}

void Hash::rehash(int c){
    int old_capacity = capacity;
    Cell **old_buckets = buckets;
    buckets = new Cell * [c]();
    capacity = c;
    for(int i=0;i<old_capacity;i++){
        Cell *current = old_buckets[i];
        while(current!=nullptr){
            int hashcode = hashCode(current->name)%c;
            Cell *temp = current->next;
            current->next = buckets[hashcode];
            buckets[hashcode] = current;
            current = temp;
        }
    }
}