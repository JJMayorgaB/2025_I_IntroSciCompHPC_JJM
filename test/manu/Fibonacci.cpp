#include <iostream>
#include <chrono>

// Naive recursive Fibonacci
long long fib(int n){
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// Fast implementation Fibonacci
long long fib_fast(int n){
    if(n <= 1) return n;
    long long a = 0, b = 1, c;
    for(int i = 2; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char **argv){
    int N = std::atoi(argv[1]);
    long long result, result_fast;
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<double> elapsed, elapsed_fast;

    for(int n = 0; n <= N; ++n){
        start = std::chrono::high_resolution_clock::now();
        result = fib(n);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;

        start = std::chrono::high_resolution_clock::now();
        result_fast = fib_fast(n);
        end = std::chrono::high_resolution_clock::now();
        elapsed_fast = end - start;

        // std::cout << "fib(" << n << ") = " << result << "\n";
        std::cout << n << "\t" << elapsed.count() << "\t" << elapsed_fast.count() << "\n";
    }
    
    return 0;
}