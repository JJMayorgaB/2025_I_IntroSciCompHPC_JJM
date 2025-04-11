#include <iostream>
#include <cmath>

typedef float REAL;

REAL sumk(int k);

int main(int argc, char **argv)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    int N = std::atoi(argv[1]);

    for(int k = 1; k <= N; k++)
        std::cout << k << "\t" << sumk(k) << "\n";
    return 0;

}

//Use k as an integer could be dangerous for the truncation error by the division by a int, better use the divison int/float and the aux varible
REAL sumk(int k)
{
    REAL suma = 0.0;
    for(int ii = 1; ii <= k; ii++){
        suma += 0.1;
    }
    REAL aux = k/10.0;
    return std::fabs(aux - suma);
}

//We can save our data with ./a.out 10000 > data.txt
//Also, we can plot it with plot "data.txt" w lp