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
    for (int i = 2; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);

    // Ejecuta la versión normal de Fibonacci y toma su tiempo
    auto start1 = std::chrono::high_resolution_clock::now();
    long long result = fib(n);
    auto end1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_1 = end1 - start1;

    //EJecuta la versión "rapida" de Fibonacci y toma su tiempo
    auto start2 = std::chrono::high_resolution_clock::now();
    long long fast_result = fib_fast(n);
    auto end2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_2 = end2 - start2;

    std::cout << n << '\t' << elapsed_1.count() << '\t' << elapsed_2.count() << std::endl;
  
    return 0;
}