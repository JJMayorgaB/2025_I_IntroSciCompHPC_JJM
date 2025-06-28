#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <execution>
#include <iomanip>
#include <thread>
#include <omp.h>
#include <string>

class PerformanceMetrics {
private:
    double sequential_time;
    double parallel_time;
    int num_threads;
    
public:
    PerformanceMetrics(double seq_time, double par_time, int threads);
    double speedup() const;
    double efficiency() const;
    void printMetrics() const;
};

void printUsage(const char* program_name);
template<typename Func>
double measureTime(Func&& func);
long long sequentialReduce(const std::vector<int>& vec);
long long parallelReduce(const std::vector<int>& vec, int policy_type);


int main(int argc, char **argv) {

    // Verificar argumentos de línea de comandos
    if (argc != 4) {
        printUsage(argv[0]);
        return 1;
    }
    
    // Parsear argumentos
    size_t vector_size = std::stoull(argv[1]);
    int num_threads = std::stoi(argv[2]);
    int execution_policy = std::stoi(argv[3]);

    // Validar argumentos
    if (vector_size <= 0 || num_threads <= 0 || execution_policy < 0 || execution_policy > 2) {
        std::cerr << "Error: Invalid arguments" << std::endl;
        printUsage(argv[0]);
        return 1;
    }
    
    // Crear y llenar el vector
    std::vector<int> vec(vector_size);
    std::iota(vec.begin(), vec.end(), 1); // Llenar con valores 1, 2, 3, ..., n
    
    // Medir tiempo secuencial (siempre con 1 thread para referencia)
    omp_set_num_threads(1);
    long long seq_result = 0;
    double sequential_time = measureTime([&]() {
        seq_result = sequentialReduce(vec);
    });
    
    // Restaurar número de threads para medición paralela
    omp_set_num_threads(num_threads);
    
    // Medir tiempo paralelo
    long long par_result = 0;
    double parallel_time = measureTime([&]() {
        par_result = parallelReduce(vec, execution_policy);
    });
    
    // Verificar que los resultados son correctos
    if (seq_result != par_result) {
        std::cerr << "Warning: Sequential and parallel results differ!" << std::endl;
        std::cerr << "Sequential result: " << seq_result << std::endl;
        std::cerr << "Parallel result: " << par_result << std::endl;
    } 
    
    // Calcular y mostrar métricas de rendimiento
    PerformanceMetrics metrics(sequential_time, parallel_time, num_threads);
    metrics.printMetrics();
    
    return 0;
}

// Constructor de PerformanceMetrics
PerformanceMetrics::PerformanceMetrics(double seq_time, double par_time, int threads) 
    : sequential_time(seq_time), parallel_time(par_time), num_threads(threads) {}

// Calcular speedup
double PerformanceMetrics::speedup() const {
    return sequential_time / parallel_time;
}

// Calcular eficiencia
double PerformanceMetrics::efficiency() const {
    return speedup() / num_threads;
}

// Imprimir métricas de rendimiento
void PerformanceMetrics::printMetrics() const {
    std::cout << std::fixed << std::setprecision(8);
    std::cout << num_threads << "\t" << speedup() << "\t" << efficiency() << std::endl;
}

// Función para medir tiempo de ejecución
template<typename Func>
double measureTime(Func&& func) {   
    std::chrono::duration<double> diff;
    auto start = std::chrono::steady_clock::now();
    func();
    auto end = std::chrono::steady_clock::now();
    diff = end-start;
    return diff.count();
}

// Función de reducción secuencial
long long sequentialReduce(const std::vector<int>& vec) {
    return std::reduce(std::execution::seq, vec.begin(), vec.end());
}

// Función de reducción paralela
long long parallelReduce(const std::vector<int>& vec, int policy_type) {
    switch(policy_type) {
        case 0: // sequential
            return std::reduce(std::execution::seq, vec.begin(), vec.end());
        case 1: // parallel
            return std::reduce(std::execution::par, vec.begin(), vec.end());
        case 2: // parallel_unsequenced
            return std::reduce(std::execution::par_unseq, vec.begin(), vec.end());
        default:
            std::cerr << "Invalid policy type. Using sequential." << std::endl;
            return std::reduce(std::execution::seq, vec.begin(), vec.end());
    }
}

// Función para mostrar uso del programa
void printUsage(const char* program_name) {
    std::cout << "Usage: " << program_name << " <vector_size> <num_threads> <execution_policy>" << std::endl;
    std::cout << "  vector_size: Size of the vector to process" << std::endl;
    std::cout << "  num_threads: Number of threads to use" << std::endl;
    std::cout << "  execution_policy: 0 (seq), 1 (par), 2 (par_unseq)" << std::endl;
    std::cout << "Example: " << program_name << " 10000000 4 2" << std::endl;
}