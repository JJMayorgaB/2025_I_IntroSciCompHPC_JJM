//Al momento de utilizar este codigo desde consola recomiendo ejecutar de la forma .\a.exe N > data.txt, donde N
//es el numero de sumas a realizar y data.txt un archivo .txt donde saldra la saliad de los datos en una tabla, esto 
//con el fin de optimizar mejor el rendimiento del codigo y poder realizar mas pruebas con distintos N de forma practica.

#include <iostream>
#include <cmath>
#include <cstdlib>

typedef float REAL;

REAL sum1(int k);
REAL sum2(int k);


int main(int argc, char **argv)
{
    std::cout.precision(8); 
    std::cout.setf(std::ios::scientific); //La salida de las sumas se da en notación cientifca

    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " N\n"; //Control de errores
        return 1;
    }

    int N = std::atoi(argv[1]); //N es el numero de sumas a realizar, ingrese este valor desde la consola

    for(int k = 1; k <= N; k++){ //Salida de los datos

        REAL s1 = sum1(k);
        REAL s2 = sum2(k); 

        std::cout << k << "\t" 
                    << s1 << "\t" 
                    << s2 << "\t" 
                    << std::fabs( 1 - (s1 / s2) ) << "\n";
    }

    return 0;
}

REAL sum1(int k) //suma de la serie armónica en orden ascendente
{
    REAL suma = 0.0;
    for(int ii = 1; ii <= k; ii++){
        REAL n = ii*1.0;
        suma += 1/n;
    }
    return suma;
}

REAL sum2(int k) //suma de la serie armónica en orden descendente
{
    REAL suma = 0.0;
    for(int ii = k; ii >= 1; ii--){
        REAL n = ii*1.0;
        suma += 1/n;
    }
    return suma;
}

