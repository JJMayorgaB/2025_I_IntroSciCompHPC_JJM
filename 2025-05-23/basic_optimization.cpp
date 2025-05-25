#include <iostream>
#include <chrono>

long long fib(int n);
long long fib_fast(int n);

int main(int argc, char **argv) {

    // Validación de argumentos
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);

    // Validación del número
    if (n < 0) {
        std::cerr << "Error: El número debe ser no negativo" << std::endl;
        return 1;
    }
    
    if (n > 93) {
        std::cerr << "Advertencia: Valores mayores a 93 pueden causar overflow en long long" << std::endl;
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    long long result1 = fib(n);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;

    auto start2 = std::chrono::high_resolution_clock::now();
    long long result2 = fib_fast(n);
    auto end2 = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed2 = end2 - start2;

    std::cout << n << "\t" << elapsed1.count() << "\t" << elapsed2.count() << std::endl;
    
    return 0;
}


// Naive recursive Fibonacci
long long fib(int n) {

    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);

}

long long fib_fast(int n) { 
    if (n <= 1) return n; 

    long long a = 0, b = 1, c;  

    for (int i = 2; i <= n; ++i) { 
        c = a + b; 
        a = b; 
        b = c;
    } 

    return b; 
}


