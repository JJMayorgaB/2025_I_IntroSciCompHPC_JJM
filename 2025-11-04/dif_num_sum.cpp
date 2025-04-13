#include <iostream>
#include <cmath>

typedef float REAL;

REAL sum1(int k);
REAL sum2(int k);


int main(int argc, char **argv)
{
    std::cout.precision(10);
    std::cout.setf(std::ios::scientific);

    int N = std::atoi(argv[1]);

    for(int k = 1; k <= N; k++){
        std::cout << k << "\t" 
                    << sum1(k) << "\t" 
                    << sum2(k) << "\t" 
                    << std::fabs( 1 - (sum1(k) / sum2(k)) ) << "\n";
    }

    return 0;
}

REAL sum1(int k)
{
    REAL suma = 0.0;
    for(int ii = 1; ii <= k; ii++){
        REAL n = ii*1.0;
        suma += 1/n;
    }
    return suma;
}

REAL sum2(int k)
{
    REAL suma = 0.0;
    for(int ii = k; ii >= 1; ii--){
        REAL n = ii*1.0;
        suma += 1/n;
    }
    return suma;
}

