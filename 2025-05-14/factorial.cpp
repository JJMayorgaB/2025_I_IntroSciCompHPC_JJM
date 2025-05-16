#include "factorial.h"

long factorial(long number)
{
    if (0 == number) return 1;
    if (number < 0){
        std::cerr << "Negative numbers not allowed. Returning -1\n";
        return -1;
    }
    return number < 0 ? number : factorial(number-1)*number;
}


int parity(int number){
    return (number % 2 == 0) ? 1 : -1;
}

