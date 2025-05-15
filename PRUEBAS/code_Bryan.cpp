#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int &size);

int main(int argc, char **argv)
{
    int ii, jj;
    ii = 0;
    jj = -1;

    // Se llaman estas funciones pero no se usan en alguna otra parte del código
    foo(ii, jj);
    foo(jj, ii);
    baz(25.9);

    const int NX = 2, NY = 3, NZ = 4;
    double *x, y[NY]{0.0}, z[NZ]{0.0};
    x = new double[NX];
    std::fill(x, x + NX, 0.0);

    //int ii, jj, kk; No se deben re declarar variables, además la variable kk no se le da uso

    print_array(x, NX);
    print_array(y, NY);
    print_array(z, NZ);
    std::cout << std::endl;

    for (ii = 0; ii < NX; ++ii)
    {
        x[ii] = jj;
    }
    print_array(x, NX);
    print_array(y, NY);
    print_array(z, NZ);
    std::cout << std::endl;
    for (jj = 0; jj < NY; ++jj)
    {
        if(jj < NX){
            x[jj] = ii;
        }
        y[jj] = jj;
    }
    //print_array(x - NY, NY);
    //print_array(y - NZ, NZ);
    //print_array(z + NZ + NY, NX);
    std::cout << std::endl;

    delete[] x;
    return EXIT_SUCCESS;
}

int foo(int a, int b)
{
    // Evitar divisiones por cero
    if (b == 0 || a == 0 || bar(a, b) == 0){
        std::cout << "Error: división por cero." << std::endl;
        return 0;
    }
    return a / b + b / bar(a, b) + b / a;
}

int bar(int a, int b)
{
    int c = std::abs(a);
    return c + a - b;
}

double baz(double x)
{
    if (x == 0){
        return 0;
    }
    return std::sqrt(x);
}

void print_array(const double data[], const int &size)
{
    std::cout << std::endl;
    for (int ii = 0; ii < size; ++ii)
    {
        std::cout << data[ii] << "  ";
    }
}