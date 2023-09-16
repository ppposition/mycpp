#ifndef MYRESET_H
#define MYRESET_H

#include <string>

template<typename T>
class MyReset
{
private:
    std::string name;
    T value;

public:
    MyReset();
    MyReset(std::string n, T v);
    void print() const;
    bool operator<(const MyReset& other) const;
};

#endif // RESET_H
