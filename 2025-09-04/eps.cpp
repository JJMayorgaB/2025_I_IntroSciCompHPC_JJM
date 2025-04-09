#include <iostream>
#include <cstdlib>

typedef float REAL;

void eps(const int iteration);

int main(int argc, char **argv)
{   
    std::cout.precision(20);
    std::cout.setf(std::ios::scientific);
    int N = std::atoi(argv[1]);

    eps(N);

    return 0;

}

void eps(const int iteration)
{

    REAL eps = 1.0;

    for(int ii = 1; ii < iteration; ii++)
    {
        eps /= 2;
        REAL one = 1.0 + eps;

        std::cout << ii << ". " << one << "\t Precision: " << eps << std::endl;
    }

}