#ifndef _ANIMAL_H
#define _ANIMAL_H
template<typename T>
class Animal
{
private:
    char name[10];
    T age;
public:
    Animal(char n[], T a);
    virtual void self_int() const;
    void pass_year();
    ~Animal();
};
#endif