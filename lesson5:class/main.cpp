#include "MyReset.h"
#include "MyReset.cpp"
int main() {
    MyReset<int> r1("position",12);
    MyReset<int> r2;
    r2.print();
    if(r2 < r1)
        r1.print();
    return 0;
}
