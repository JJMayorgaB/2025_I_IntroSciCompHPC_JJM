#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {
    int num_threads = omp_get_max_threads();
    std::cout << "Number of threads: " << num_threads << std::endl;

#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int actual_threads = omp_get_num_threads();

        #pragma omp critical
        {
            std::cout << "Hola mundo, soy el thread " << thread_id 
                      << " de un total de threads de " << actual_threads << std::endl;
        }
    }
    return 0;
}
