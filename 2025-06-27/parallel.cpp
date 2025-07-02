#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <omp.h>
#include <cmath>

int main(int argc, char* argv[]) {

    if (argc < 4) {                           
        std::cerr << "Uso: " << argv[0] << " <tamaño_vector> <num_threads> <politica: 0=seq, 1=par, 2=par_unseq>\n";
        return 1;
    }

    const int N = std::atoi(argv[1]);
    const int num_threads = std::atoi(argv[2]);
    const int policy = std::atoi(argv[3]);

    omp_set_num_threads(num_threads);

    const int seed = 10;
    std::vector<double> vec(N);
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dist(1.0, 2.0);
    
    for (auto& x : vec) {
        x = dist(gen);
    }

    double sum = 0.0;
    double start = omp_get_wtime();

    switch (policy ) {
    case 0: { //seq
        sum = std::accumulate(vec.begin(), vec.end(), 0.0,
            [](double acc, double x) {
                return acc + std::sqrt(std::log(x)/x) + x;
            });
        break;
    }
    case 1: { //par
        #pragma omp parallel for reduction(+:sum) 
        for (int i = 0; i < N; ++i) {
            sum += std::sqrt(std::log(vec[i])/vec[i]) + vec[i];
        }
        break;
    }
    case 2: { //par_unseq
        #pragma omp parallel for simd reduction(+:sum) 
        for (int i = 0; i < N; ++i) {
            sum += std::sqrt(std::log(vec[i])/vec[i]) + vec[i];
        }
        break;
    }
    default:
        std::cerr << "Politica de ejecución no valida\n";
        return 1;
    }

    double end = omp_get_wtime();

    std::cout << end - start << "\n";

    return 0;
}

