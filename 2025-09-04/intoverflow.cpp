#include <iostream>

int main(void)
{

    double x = -1.5e38;
    double y = -1.5e38;
    double z = 1;

    double a1 = x + y;
    double a2 = y + z;

    std::cout << a1 + z << std::endl;
    std::cout << x + a2 << std::endl;

    return 0;
}