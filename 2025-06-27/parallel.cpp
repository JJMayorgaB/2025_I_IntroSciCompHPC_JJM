#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <omp.h>
#include <cmath>
#include <algorithm>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (argc < 4) {                             //orden de los 3 argumentos en consola
        std::cerr << "Uso: " << argv[0] << " <tamaño_vector> <num_threads> <modo: 0=seq, 1=par, 2=par_unseq>\n";
        return 1;
    }

    const int N = std::atoi(argv[1]);
    const int num_threads = std::atoi(argv[2]);
    const int policy_type = std::atoi(argv[3]);

    // Configuración de hilos
    omp_set_num_threads(num_threads);

    // Generar vector de números aleatorios (reproducible)
    const int seed = 10;
    std::vector<double> vec(N);
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dist(1.0, 2.0);
    
    for (auto& x : vec) {
        x = dist(gen);
    }

    // Medir tiempo secuencial (siempre con 1 thread para referencia)
    omp_set_num_threads(1);
    double seq_result = 0.0;
    double startseq = omp_get_wtime();
    
    // Cálculo secuencial manual
    for (int i = 0; i < N; ++i) {
        seq_result += std::log(vec[i]);
    }
    
    double endseq = omp_get_wtime();

    // Suma del vector según el modo seleccionado
    omp_set_num_threads(num_threads);

    double sum = 0.0;
    double start = omp_get_wtime();

    switch(policy_type) {
        case 0: // sequential
            for (int i = 0; i < N; ++i) {
                sum += std::log(vec[i]);
            }
            break;
            
        case 1: // parallel with OpenMP
            #pragma omp parallel for reduction(+:sum)
            for (int i = 0; i < N; ++i) {
                sum += std::log(vec[i]);
            }
            break;
            
        case 2: // parallel_unsequenced with OpenMP SIMD
            #pragma omp parallel for simd reduction(+:sum)
            for (int i = 0; i < N; ++i) {
                sum += std::log(vec[i]);
            }
            break;
            
        default:
            std::cerr << "Invalid policy type. Using sequential." << std::endl;
            for (int i = 0; i < N; ++i) {
                sum += std::log(vec[i]);
            }
            break;
    }

    double end = omp_get_wtime();

    double speedup = (endseq-startseq)/(end - start);
    double efficiency = speedup / num_threads;

    std::cout << std::fixed << std::setprecision(8);
    std::cout << num_threads << "\t" << speedup << "\t" << efficiency << std::endl;

    return 0;
}