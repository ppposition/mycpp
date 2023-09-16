#ifndef RESET_H
#define RESET_H

#include <string>

template<typename T>
class Reset
{
private:
    std::string name;
    T value;

public:
    Reset();
    Reset(std::string n, T v);
    void print() const;
    bool operator<(const Reset& other);
};

#endif // RESET_H
