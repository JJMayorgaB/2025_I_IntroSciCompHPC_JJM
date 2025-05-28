#include <iostream>
#include <chrono>

// Naive recursive Fibonacci
long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

long long fib_fast(int n){
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n ; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char **argv) {
    
    int n = atoi(argv[1]);
    auto start_fib = std::chrono::high_resolution_clock::now();

    long long result_fib = fib(n);

    auto end_fib = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_fib = end_fib - start_fib;

    auto start_fib_fast = std::chrono::high_resolution_clock::now();

    long long result_fib_fast = fib_fast(n);

    auto end_fib_fast = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_fib_fast = end_fib_fast - start_fib_fast;

    // Impresion -> n, número de la serie, tiempo método recursivo, Tiempo método rápido 
    std::cout << n << "\t" 
              << result_fib_fast << "\t"
              << elapsed_fib.count() << "\t" 
              << elapsed_fib_fast.count() << "\n";

    return 0;
}