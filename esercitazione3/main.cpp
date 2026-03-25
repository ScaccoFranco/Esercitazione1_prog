#include <iostream>
#include "rational.hpp"
rational<int> r(4,6);
int main(void) {
    rational<int> r1(-1,0);
    rational<int> r2(1,0);
    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n";
    std::cout << "r1 + r2 = " << r1 + r2 << "\n";
    std::cout << "r1 - r2 = " << r1 - r2 << "\n";
    std::cout << "r1 / r2 = " << r1 / r2 << "\n";
    std::cout << "r1 * r2 = " << r1 * r2 << "\n";
    return 0;
}