#include <iostream>
#include "rational.hpp"

int main(void) {

    rational<int> r1(-2,3);
    rational<int> r2(9,10);
    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n";
    std::cout << "r1 + r2 = " << r1 + r2 << "\n";
    std::cout << "r1 - r2 = " << r1 - r2 << "\n";
    std::cout << "r1 / r2 = " << r1 / r2 << "\n";
    std::cout << "r1 * r2 = " << r1 * r2 << "\n";


    
    rational<int> r3(-1,0);
    rational<int> r4(1,0);
    std::cout << "r3 = " << r3 << "\n";
    std::cout << "r4 = " << r4 << "\n";
    std::cout << "r3 + r4 = " << r3 + r4 << "\n";
    std::cout << "r3 - r4 = " << r3 - r4 << "\n";
    std::cout << "r3 / r4 = " << r3 / r4 << "\n";
    std::cout << "r3 * r4 = " << r3 * r4 << "\n";
    return 0;
}