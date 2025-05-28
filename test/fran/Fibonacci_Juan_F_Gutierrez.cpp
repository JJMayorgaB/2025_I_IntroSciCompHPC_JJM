#include <iostream>
#include <chrono>

// Naive recursive Fibonacci
long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

long long fib_fast(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i=2; i<=n; ++i){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    auto start1 = std::chrono::high_resolution_clock::now();

    long long result1 = fib(n);

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;

    auto start2 = std::chrono::high_resolution_clock::now();

    long long result2 = fib_fast(n);

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;

    //std::cout << "fib(" << n << ") = " << result1 << "\n";
    std::cout << n << "  "<< elapsed1.count()/4.2181e-05 << " "<< elapsed2.count()/9e-08 << "\n"; 
    return 0;
}