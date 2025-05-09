#include <iostream>
#include <cmath>

typedef float REAL;

int factorial(int n);
REAL fnaive(REAL x, int N);
REAL fsmart(REAL x, int N);

int main(void)
{
  std::cout.precision(16); 
  std::cout.setf(std::ios::scientific);

  REAL x = 1.234534534;
  const REAL exact = std::exp(-x);

  for (int NMAX = 0; NMAX <= 50; ++NMAX) {
    std::cout << NMAX
              << "\t" << fnaive(x, NMAX)
              << "\t" << std::fabs(fnaive(x, NMAX) - exact)/exact
              << "\t" << fsmart(x, NMAX)
              << "\t" << std::fabs(fsmart(x, NMAX) - exact)/exact
              << std::endl;
  }
  return 0;
}

REAL fnaive(REAL x, int N)
{
    
    REAL exp = 0;
    REAL term = 0;

    for(int n = 0; n<= N; ++n){

        term = pow(-x,n) / factorial(n);
        exp += term;

    }

  return exp;
    
}

int factorial(int n)
{
  if (n <= 0) return 1;
  return n*factorial(n-1);
}

REAL fsmart(REAL x, int N)
{

    REAL exp = 1;
    REAL term = 1;

    for(int n = 0; n<= N-1; ++n){

        term = (-x*term)/(n+1);
        exp += term;

    }

  return exp;

}