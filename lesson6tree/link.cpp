#include<iostream>
using namespace std;
struct link
{
    int data;
    link *next;
    link():data(0),next(nullptr){}
    link(int d):data(d),next(nullptr){}
    link(int d,link *n):data(d),next(n){}
};
void delete_tail(link *front){
    link *temp=front;
    while(temp->next!=nullptr)
        temp=temp->next;
    temp=nullptr;
}
void print(link *front){
    link *temp=front->next;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
    link *head=new link;
    link *temp=head;
    for(int i=1;i<=10;i++){
        temp->next=new link(i);
        temp=temp->next;
    }
    cout<<head->data<<endl;
    print(head);
    delete_tail(head);
    print(head); 
    return 0;
}
