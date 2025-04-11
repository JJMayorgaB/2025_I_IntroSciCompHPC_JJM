#include <iostream> 

int main(void) 
{
  int num;

  std::cout << "Escriba un numero entero, por favor:" << std::endl;

  std::cin >> num;

  if (num%2 == 0) {
    std::cout << "El numero es par" << std::endl;
  } 
  if (num%2 != 0) {
    std::cout << "El numero es impar" << std::endl;
  } 

  //else {
  //cout << "El numero es impar" << endl;
  //}

  return 0;
}