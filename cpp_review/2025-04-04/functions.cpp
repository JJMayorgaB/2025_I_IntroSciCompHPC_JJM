#include <iostream> 

void print_numbers(int nmax);

int main(void) 
{
    print_numbers(30);

  return 0;
}

void print_numbers(int nmax)
{  
    std::cout << nmax << std::endl;
    for (int n = 1; n <= nmax; n++) {
    std::cout << n << std::endl;
  } 
}