#include <iostream>
#include <cstdlib>

typedef float REAL;

void floatflow(REAL & a, const int iteration);

int main(int argc, char **argv)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    int N = std::atoi(argv[1]);

    REAL x = 1.0;

    floatflow(x, N);

    return 0;
}

void floatflow(REAL & a, const int iteration)
{

    REAL under = a;
    REAL over = a;
    
    for(int ii = 0; ii < iteration; ii++){

        under /= 2;
        over *= 2;

        std::cout << ii << ". " << under << "\t" << over << std::endl;

    }

}