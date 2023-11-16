#ifndef _DOG_H
#define _DOG_H
#include"Animal.h"
template<typename T>
class Dog : public Animal<T>{
private:
    T weight;
public:
    Dog(char n[], T a, T w);
    ~Dog();
    void burk() const;
    void self_int() const override;
};

#endif