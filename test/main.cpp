#include <iostream>
#include "../libs/bignum.h"

int main()
{
    BigNum n(100000000000001);
    std::cout << n.get() << std::endl;
    return 0;
}