#include <iostream>
#include "factorial.h"

int main(void)
{
    std::cout << factorial(0) << std::endl;
    std::cout << factorial(0.5) << std::endl;
    std::cout << factorial(-3) << std::endl;
    std::cout << factorial(31) << std::endl;
    std::cout << factorial(-1) << std::endl;
    return 0;
}