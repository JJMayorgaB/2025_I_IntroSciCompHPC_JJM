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

    // Evitamos división por cero
    if (jj != 0) foo(ii, jj);
    if (ii != 0) foo(jj, ii);
 
    baz(25.9);

    const int NX = 2, NY = 3, NZ = 4;

    double *x = new double[NX]();  // Inicializamos con ceros
    double y[NY] = {0};            // Inicializamos con ceros
    double z[NZ] = {0};            // Inicializamos con ceros
    
    print_array(x, NX);
    print_array(y, NY);
    print_array(z, NZ);
    
    std::cout << std::endl;

    for (ii = 0; ii < NX; ++ii) {

        x[ii] = ii;

    }

    //Arreglos inicializados correctamente
    print_array(x, NX);
    print_array(y, NY);
    print_array(z, NZ);

    std::cout << std::endl;

    for (int jj = 0; jj < NY; ++jj) {
        
        if (jj < NX){    // evitar overflow al acceder a limites fuera de x
            
            x[jj] = ii;

        }  

        y[jj] = jj;

    }

    print_array(x, NX);   // Imprimimos x correctamente
    print_array(y, NY);   // Imprimimos y correctamente
    print_array(z, NZ);   // Imprimimos z correctamente
    std::cout << std::endl;

    // Liberamos la memoria asignada dinámicamente
    delete[] x;

    return EXIT_SUCCESS;

    }

    int foo(int a, int b)
    {
      // Evitar divisiones por cero
      if (b == 0 || a == 0 || bar(a, b) == 0) return 0;
      return a / b + b / bar(a, b) + b / a;

    }

int bar(int a, int b)
{
    int c = a;  // Cambiado de unsigned int a int para mantener coherencia
    return c + a - b;
}

double baz(double x)
{

    if (x == 0) return 0;  // Corregido el operador de asignación a comparación y añadido retorno
    double v = 1-(x+1);
    return std::sqrt(x);   // Añadido el punto y coma faltante

}

void print_array(const double data[], const int & size)
{
    std::cout << std::endl;
    for (int ii = 0; ii < size; ++ii) {
        std::cout << data[ii] << "  " ;
    }
}