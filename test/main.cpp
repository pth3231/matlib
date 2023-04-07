#include <iostream>
#include <string>
#include "../libs/bignum.h"

int main()
{
    BigNum *n1 = new BigNum(1002);
    BigNum *n2 = new BigNum(3004);
    std::cout << n1->get() << std::endl;
    std::cout << n2->get() << std::endl;
    std::cout << (n1 < n2) << std::endl;
    return 0;
}