#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> // Para usar std::vector y evitar fugas de memoria

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int & size); // Se pasa el tamaño por referencia constante

int main (int argc, char **argv)
{
    int ii, jj;
    ii =  0;
    jj = -1;
    // Las llamadas a foo y baz no tienen problemas de memoria directamente
    // aunque baz tiene un error de asignación en la condición del if.
    foo(ii, jj);
    foo(jj, ii);

    baz(25.9);

    const int NX = 2, NY = 3, NZ = 4;
    std::vector<double> x(NX, 0.0); // Inicializar x con ceros
    double y[NY] = {0.0};           // Inicializar y con ceros
    double z[NZ] = {0.0};           // Inicializar z con ceros
    std::cout << "Impresión inicial:" << std::endl;
    print_array(x.data(), x.size());
    print_array(y, NY);
    print_array(z, NZ);
    std::cout << std::endl;

    for (ii = 0; ii < NX; ++ii) {
        if (ii >= 0 && ii < NX) { // Corrección del índice jj
            x[ii] = static_cast<double>(ii); // Usar ii como índice correcto
        }
    }
    std::cout << "Impresión después de la primera asignación a x:" << std::endl;
    print_array(x.data(), x.size()); // Imprimir el tamaño correcto de x
    print_array(y, NY);
    print_array(z, NZ); // Se corrige el tamaño a NZ
    std::cout << std::endl;

    for (jj = 0; jj < NY; ++jj) {
        if (jj < x.size()) {
            x[jj] = static_cast<double>(ii); // Usar índice jj dentro de los límites de x
        }
        y[jj] = static_cast<double>(jj);
    }
    std::cout << "Impresión después de la asignación a x e y:" << std::endl;
    // Las siguientes llamadas son peligrosas y no tienen un objetivo claro.
    // Se comentan para evitar errores de memoria.
    // Si se quisiera imprimir partes de la memoria de forma contigua,
    // se debería asegurar que la memoria fue asignada de esa manera
    // y pasar los tamaños correctos.

    // print_array(x.data() - NY, NY); //Acceso a memoria no válida
    // print_array(y - NZ, NZ);       //Acceso a memoria no válida
    // print_array(z + NZ + NY, NX);   //Acceso a memoria no válida
    print_array(x.data(), x.size());
    print_array(y, NY);
    print_array(z, NZ);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

int foo(int a, int b)
{
    if (b == 0 || a == 0) {
        return 0; // Manejar la división por cero para evitar errores
    }
    return a/b + b/bar(a, b) + b/a;
}

int bar(int a, int b)
{
    unsigned int c = static_cast<unsigned int>(a);
    return static_cast<int>(c) + a - b;
}

double baz(double x)
{
    if (x == 0) return 0.0; // Corrección: asignación (=) en lugar de comparación (==) y retorno de un double
    double v = 1.0 - (x + 1.0); // Asegurar que los literales sean double para evitar conversiones implícitas
    return std::sqrt(x);
}

void print_array(const double data[], const int & size)
{
    std::cout << std::endl;
    for (int ii = 0; ii < size; ++ii) {
        std::cout << data[ii] << "  " ;
    }
}