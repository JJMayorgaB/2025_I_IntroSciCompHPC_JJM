#include <iostream>
#include <chrono>
#include <cstdlib>

// Naive recursive Fibonacci
long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
//fast recursive Fibonacci
    long long fib_fast(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i<= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;

}

int main(int argc , char* argv[]) {

    int n = atoi(argv[1]);

    auto start_s = std::chrono::high_resolution_clock::now();
    long long result_s = fib(n);
    auto end_s = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_s = end_s - start_s;

    auto start_f = std::chrono::high_resolution_clock::now();
    long long result_f = fib_fast(n);
    auto end_f = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_f = end_f - start_f;

    std::cout << n << "  " << elapsed_s.count() << " " << elapsed_f.count() << "\n";
    return 0;
}