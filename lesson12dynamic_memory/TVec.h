#ifndef _TVEC_H
#define _TVEC_H
#include<iostream>
using namespace std;
template<typename T>
class TVec
{
private:
    static allocator<T> alloc;
    void chk_n_alloc(){if(size()==capacity()) reallocate();}
    void free();
    void reallocate();
    T *elements; //指向数组首元素
    T *first_free; //数组第一个空闲元素的指针
    T *cap; //数组尾后位置的指针
public:
    TVec(/* args */):elements(nullptr),first_free(nullptr),cap(nullptr){};
    TVec(const TVec &);
    TVec<T> &operator=(const TVec<T> &);
    ~TVec();
    void push_back(const T&);
    pair<T*,T*> alloc_n_copy(const T *b, const T *e);
    size_t size() const{return first_free-elements;}
    size_t capacity() const{return cap-elements;}
    T *begin() const{return elements;}
    T *end() const{return first_free;}
    T &operator[](size_t n){return elements[n];}
};
#endif