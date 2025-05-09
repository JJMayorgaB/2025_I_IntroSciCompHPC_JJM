#include <iostream>
#include <cmath>
#include <cstdlib>

typedef float REAL;

REAL sum1(int k);
REAL sum2(int k);
REAL sum3(int k);

int main(int argc, char **argv)
{
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    int N = std::atoi(argv[1]);

    for(int k = 1; k <= N; k++){
        std::cout << k << "\t" 
                    << sum1(k) << "\t" 
                    << sum2(k) << "\t" 
                    << sum3(k) << "\t" 
                    << std::fabs(sum1(k) - sum3(k))/sum3(k) << "\t" 
                    << std::fabs(sum2(k) - sum3(k)) / sum3(k) <<"\n";   
    }
        
    return 0;
}

REAL sum1(int k)
{
    REAL suma = 0.0;
    for(int ii = 1; ii <= 2*k; ii++){
        REAL n = ii*1.0;
        suma += pow(-1, n)* n / (n+1);
    }
    return suma;
}

REAL sum2(int k)
{
    REAL suma1 = 0.0;
    REAL suma2 = 0.0;
    for(int ii = 1; ii <= k; ii++){
        REAL n = ii*1.0;
        suma1 += -(2*n-1)/2*ii;
        suma2 += 2*n/(2*n+1);
    }
    return suma2 - suma1;
}

REAL sum3(int k)
{
    REAL suma = 0.0;
    for(int ii = 1; ii <= k; ii++){
        REAL n = ii/1.0;
        suma += 1 / ( 2 * n * (2 * n + 1));
    }
    return suma;
}