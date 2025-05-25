#include <iostream>
#include <chrono>

long long fib(int n);
long long fib_fast(int n);

int main(int argc, char **argv) {

    int n = std::atoi(argv[1]);

    auto start = std::chrono::high_resolution_clock::now();
    long long result = fib(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end - start;

    auto start = std::chrono::high_resolution_clock::now();
    long long result = fib_fast(n);
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed2 = end - start;

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


