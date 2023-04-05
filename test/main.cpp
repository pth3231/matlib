#include <iostream>
#include <string>
#include "../libs/bignum.h"

int main()
{
    BigNum n(100000000000001);
    std::cout << n.get() << std::endl;
    n.set((int64_t) 1000);
    std::cout << n.get() << std::endl;
    n.set("-232333");
    std::cout << n.get() << std::endl;
    n.set(-1000.);
    std::cout << n.get() << std::endl;
    return 0;
}