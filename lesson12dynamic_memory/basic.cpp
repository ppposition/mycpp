#include<iostream>
#include<memory>
#include<list>
#include<string>
using namespace std;
int main(){
    shared_ptr<string> p1 = make_shared<string>("jishen");
    cout<<*p1<<endl;
    shared_ptr<list<int>> p2 = make_shared<list<int>>();
    for(int i=0;i<10;i++)
        p2->push_back(i);
    for(auto it = p2->begin();it!=p2->end();it++)
        cout<<*it<<endl;
    shared_ptr<int> p3(new int(1024));
    shared_ptr<int> p4(p3);
    *p4=1;
    cout<<*p3<<endl;
    int *p5 = new int [10];
    int *p6 = p5;
    for(int i=0;i<10;i++)
        cout<<p6[i];
    cout<<endl;
    unique_ptr<int[]> p7(new int[10]);
    for(int i=0;i<10;i++)
        cout<<p7[i];
    p7.release();
    cout<<endl;
    allocator<string> alloc;
    auto p8 = alloc.allocate(5);
    for(int i=0;i<5;i++)
        alloc.construct(p8+i,"js"+to_string(i));
    for(int i=0;i<5;i++)
        cout<<p8[i]<<endl;
    auto p9 = alloc.allocate(10);
    auto temp = uninitialized_copy(p8, p8+5, p9);
    uninitialized_fill_n(temp, 5, "js");
    for(size_t i=0;i<10;i++)
        cout<<p9[i]<<endl;
    return 0;
}