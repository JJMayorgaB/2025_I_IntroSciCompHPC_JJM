//Al momento de utilizar este codigo desde consola recomiendo ejecutar de la forma .\a.exe N > data.txt, donde N
//es el numero de sumas a realizar, esto con el fin de optimizar mejor el rendimiento del codigo y poder realizar
//mas pruebas con distintos N de forma practica.

#include <iostream>
#include <cmath>

typedef float REAL;

REAL sum1(int k);
REAL sum2(int k);


int main(int argc, char **argv)
{
    std::cout.precision(16); 
    std::cout.setf(std::ios::scientific); //La salida de las sumas se da en notación cientifca

    int N = std::atoi(argv[1]); //N es el numero de sumas a realizar, ingrese este valor desde la consola

    for(int k = 1; k <= N; k++){ //Salida de los datos
        std::cout << k << "\t" 
                    << sum1(k) << "\t" 
                    << sum2(k) << "\t" 
                    << std::fabs( 1 - (sum1(k) / sum2(k)) ) << "\n";
    }

    return 0;
}

REAL sum1(int k)
{
    REAL suma = 0.0;
    for(int ii = 1; ii <= k; ii++){
        REAL n = ii*1.0;
        suma += 1.0/n;
    }
    return suma;
}

REAL sum2(int k)
{
    REAL suma = 0.0;
    for(int ii = k; ii >= 1; ii--){
        REAL n = ii*1.0;
        suma += 1.0/n;
    }
    return suma;
}

