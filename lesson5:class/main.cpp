#include "Reset.h"

int main() {
    Reset<int> resetObject("position",12);
    resetObject.print();

    return 0;
}
