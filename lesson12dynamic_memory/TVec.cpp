#include"TVec.h"
#include<memory>

// 在类外定义静态成员
template<typename T>
allocator<T> TVec<T>::alloc;

template<typename T>
TVec<T>::TVec(const TVec &t)
{
    auto newdata = alloc_n_copy(t.begin(), t.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
TVec<T> &TVec<T>::operator=(const TVec<T> &t)
{
    auto data = alloc_n_copy(t.begin(), t.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template<typename T>
TVec<T>::~TVec()
{
    free();
}

template<typename T>
void TVec<T>::push_back(const T &t){
    chk_n_alloc();
    alloc.construct(first_free++,t);
}

template<typename T>
pair<T*, T*> TVec<T>::alloc_n_copy(const T *b, const T *e){
    auto data = alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}

template<typename T>
void TVec<T>::free(){
    if(elements){
        for(auto p=first_free;p!=elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap-elements);
    }
}

template<typename T>
void TVec<T>::reallocate(){
    auto newcapacity = size() ? 2*size():1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0;i!=size();i++)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements+newcapacity;
}