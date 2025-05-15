#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int & size);

int main (int argc, char **argv)
{
  int ii = 3, jj = 4;
  std::cout << foo(ii, jj) << "\t" << foo(jj, ii) << "\t" << baz(25.9) << "\n";

  const int NX = 2, NY = 3, NZ = 4;
  double *x, y[NY], z[NZ];
  x = new double [NX];
  std::cout << "Arreglo x: "; print_array(x, NX);
  std::cout << "Arreglo y: "; print_array(y, NY);
  std::cout << "Arreglo z: "; print_array(z, NZ);

  for (ii = 0; ii < NX; ++ii) {
    x[ii] = ii; 
  }
  std::cout << "Nuevo arreglo x: "; print_array(x, NX);
  std::cout << "Arreglo y: "; print_array(y, NY);
  std::cout << "Primeros 3 elementos del arreglo z: "; print_array(z, NY);

  for (jj = 0; jj < NY; ++jj) {
    y[jj] = jj;
  }
  std::cout << "Nuevo arreglo y: "; print_array(y, NY);
  std::cout << "Primeros 2 elementos del arreglo z: "; print_array(z, NX);

  delete[] x; //Libera la memoria dinámica.

  return EXIT_SUCCESS;
}

int foo(int a, int b)
{
  if (a == 0 || b == 0) return 0;

  return a/b + b/bar(a, b) + b/a; //Al ser enteros, la división se redondea.
}

int bar(int a, int b)
{
  unsigned int c = a; //Si a es negativo, c será positivo y grande.
  return c + a - b;
}

double baz(double x)
{
  if (x == 0) return 0.0;
  return std::sqrt(x);
}

void print_array(const double data[], const int & size)
{
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  " ;
  }
  std::cout << "\n";
}