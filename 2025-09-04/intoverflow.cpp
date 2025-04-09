#include <iostream>

void integraloverflow(int & a);

int main(void)
{

    int x = 1;

    integraloverflow(x);

    return 0;

}

// We wanna obtain the integral overflow in c++ with a simple code.
void integraloverflow(int & a)
{
    
    int n = 0;

    while(a > 0){

        a *= 2;
        n++ ;
        std::cout << n << ". " << a << std::endl;
        

    }

    std::cout << "Overflow occurred! (Undefined behavior) at interation #" << n << std::endl;

}