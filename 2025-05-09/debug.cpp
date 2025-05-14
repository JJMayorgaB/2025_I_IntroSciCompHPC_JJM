#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int & size);

int main (int argc, char **argv)
{
  int ii, jj;
  ii =  0;
  jj = -1;
  foo(ii, jj);
  foo(jj, ii);
 
  baz(25.9);

    const int NX = 2, NY = 3, NZ = 4;
  double *x, y[NY], z[NZ];
  x = new double [NX];
  int ii, jj, kk;
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << std::endl;

  for (ii = 0; ii < NX; ++ii) {
    x[jj] = ii;
  }
  print_array(x, NZ);
  print_array(y, NY);
  print_array(z, NZ + NY);
  std::cout << std::endl;
  for (jj = 0; jj < NY; ++jj) {
    x[jj] = ii;
    y[jj] = jj;
  }
  print_array(x-NY, NY);
  print_array(y-NZ, NZ);
  print_array(z + NZ + NY, NX);
  std::cout << std::endl;

   return EXIT_SUCCESS;
}

int foo(int a, int b)
{
  return a/b + b/bar(a, b) + b/a;
}

int bar(int a, int b)
{
  unsigned int c = a;
  return c + a - b;
}

double baz(double x)
{
  if (x = 0) return;
  double v = 1-(x+1);
  return std::sqrt(x)
}

void print_array(const double data[], const int & size)
{
  std::cout << std::endl;
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  " ;
  }
}