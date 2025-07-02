/*
Antes de iniciar el codigo se debe advertir que se decidio trabajar con la paralelización directa con OpenMP
en vez de usar la librería de paralelización de C++ (std::execution) debido a que al realizar pruebas diversas variando 
el tamaño del vector, cantidad de hilos y funciones a paralelizar, no se observo una mejora significativa en el rendimiento
y peor aun ninguna diferencia entre las distintas politicas de ejecución (secuencial, paralela y paralela con
vectorización), al inicio se considero que la función std::reduce era poco exigente y no se notaba la diferencia entre
las distintas politicas de ejecución, pero usando std::transform_reduce no se observo una mejora al utilizar funciones mas
complejas que aumentaban siginificativamente el tiempo de ejecución. Puesto que aunque se observo usando htop que la ejecución
en efecto estaba siendo paralelizada, el tiempo de ejecución no se reducia significativamente. Por otro lado, al usar OpenMP
directamente si se pudo observar las diferencias entre las distintas politicas de ejecución y por estos motivos se opto por
usar OpenMP directamente para la paralelización del código.
*/

// Bibliotecas necesarias para el programa
#include <iostream>    // Para entrada/salida estándar
#include <vector>      // Para usar vectores dinámicos
#include <numeric>     // Para funciones numéricas como accumulate
#include <random>      // Para generación de números aleatorios
#include <omp.h>       // Para OpenMP (paralelización)
#include <cmath>       // Para funciones matemáticas (exp, cos, tan, log10)

int main(int argc, char* argv[]) {

    // Verificar que se proporcionen los argumentos correctos
    if (argc < 4) {                           
        std::cerr << "Uso: " << argv[0] << " <tamaño_vector> <num_threads> <politica: 0=seq, 1=par, 2=par_unseq>\n";
        return 1;
    }

    // Obtener parámetros de la línea de comandos
    const int N = std::atoi(argv[1]);           // Tamaño del vector
    const int num_threads = std::atoi(argv[2]); // Número de hilos para paralelización
    const int policy = std::atoi(argv[3]);      // Política de ejecución (0, 1, o 2)

    // Configurar el número de hilos para OpenMP
    omp_set_num_threads(num_threads);

    // Generar vector con números aleatorios reproducibles
    const int seed = 10;                        // Semilla fija para reproducibilidad
    std::vector<double> vec(N);                 // Vector de tamaño N
    std::mt19937 gen(seed);                     // Generador Mersenne Twister
    std::uniform_real_distribution<double> dist(1.0, 2.0); // Distribución uniforme entre 1.0 y 2.0
    
    // Llenar el vector con números aleatorios
    for (auto& x : vec) {
        x = dist(gen);
    }

    // Variables para medición de tiempo y resultado
    double sum = 0.0;                           // Suma total del vector transformado
    double start = omp_get_wtime();             // Tiempo de inicio

    // Seleccionar estrategia de cálculo según la política especificada
    switch (policy ) {
    case 0: { //seq - Ejecución secuencial
        // Usar std::accumulate con función lambda para transformación matemática
        sum = std::accumulate(vec.begin(), vec.end(), 0.0,
            [](double acc, double x) {
                // Función matemática compleja: exp(cos(x)) * tan(x/2) + log10(x)
                return acc + std::exp(std::cos(x)) * std::tan(x/2.0) + std::log10(x);
            });
        break;
    }
    case 1: { //par - Ejecución paralela con OpenMP
        // Paralelizar el bucle for con reducción para la suma
        #pragma omp parallel for reduction(+:sum) 
        for (int i = 0; i < N; ++i) {
            // Aplicar la misma función matemática compleja a cada elemento
            sum += std::exp(std::cos(vec[i])) * std::tan(vec[i]/2.0) + std::log10(vec[i]);
        }
        break;
    }
    case 2: { //par_unseq - Ejecución paralela con vectorización SIMD
        // Paralelizar con SIMD (Single Instruction, Multiple Data)
        #pragma omp parallel for simd reduction(+:sum) 
        for (int i = 0; i < N; ++i) {
            // Misma función matemática, pero optimizada para vectorización
            sum += std::exp(std::cos(vec[i])) * std::tan(vec[i]/2.0) + std::log10(vec[i]);
        }
        break;
    }
    default:
        std::cerr << "Politica de ejecución no valida\n";
        return 1;
    }

    // Medir tiempo final y calcular duración
    double end = omp_get_wtime();

    // Mostrar el tiempo de ejecución en segundos
    std::cout << end - start << "\n";

    return 0;
}
