#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono> // For timing the functions
#include <random>

// Function to allocate a 2D array dynamically
double** allocate_matrix(int N);

// Function to deallocate a 2D array
void deallocate_matrix(double** matrix, int N);

// Function to initialize a matrix with random values
void initialize_matrix_random(double** matrix, int N);

// Utility function to print a matrix
void print_matrix(double** matrix, int N);

// --- Traditional Matrix Multiplication ---
// Uses the standard i-j-k loop order.
void matrix_mult_traditional(double** A, double** B, double** C, int N);

// --- Blocked Matrix Multiplication ---
// Uses tiling/blocking for better cache performance.
void matrix_mult_blocking(double** A, double** B, double** C, int N, int BLOCK_SIZE);

int main(int argc, char **argv) {
    

    const int N = std::atoi(argv[1]); // Dimension of the matrices, try larger values like 512 or 1024 to see performance difference
    const int BLOCK_SIZE = std::atoi(argv[2]); // Dimension of the blocks
    const int SEED = std::atoi(argv[3]); //SEED

    srand(SEED);

    // --- Allocate Matrices ---
    double** A = allocate_matrix(N);
    double** B = allocate_matrix(N);
    double** C_traditional = allocate_matrix(N);
    double** C_blocked = allocate_matrix(N);

    // --- Initialize Matrices ---
    initialize_matrix_random(A, N);
    initialize_matrix_random(B, N);
    // C matrices are already initialized to zero by allocate_matrix

    /*
    std::cout << "Matrix A:" << std::endl;
    print_matrix(A, N);
    std::cout << "\nMatrix B:" << std::endl;
    print_matrix(B, N);
    */
    
    // --- Perform Traditional Multiplication ---
    //auto start_trad = std::chrono::high_resolution_clock::now();
    //matrix_mult_traditional(A, B, C_traditional, N);
    //auto end_trad = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> diff_trad = end_trad - start_trad;

    //std::cout << "\n--- Result from Traditional Multiplication (" << diff_trad.count() << " s) ---" << std::endl;
    //print_matrix(C_traditional, N);

    // --- Perform Blocked Multiplication ---
    auto start_block = std::chrono::high_resolution_clock::now();
    matrix_mult_blocking(A, B, C_blocked, N, BLOCK_SIZE);
    auto end_block = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_block = end_block - start_block;

    std::cout << N << "\t" << BLOCK_SIZE << "\t"<< diff_block.count() << std::endl;
    //print_matrix(C_blocked, N);


    // --- Deallocate Memory ---
    deallocate_matrix(A, N);
    deallocate_matrix(B, N);
    deallocate_matrix(C_traditional, N);
    deallocate_matrix(C_blocked, N);

    return 0;
}

// Function to allocate a 2D array dynamically
double** allocate_matrix(int N) {
    double** matrix = new double*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new double[N](); // Initialize elements to 0.0
    }
    return matrix;
}

// Function to deallocate a 2D array
void deallocate_matrix(double** matrix, int N) {
    if (matrix) {
        for (int i = 0; i < N; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

// Function to initialize a matrix with random values
void initialize_matrix_random(double** matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = static_cast<double>(rand()) / RAND_MAX * 10.0;
        }
    }
}

// Utility function to print a matrix
void print_matrix(double** matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout.width(8);
            std::cout << std::fixed << std::setprecision(2) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// --- Traditional Matrix Multiplication ---
// Uses the standard i-j-k loop order.
void matrix_mult_traditional(double** A, double** B, double** C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double sum = 0.0;
            for (int k = 0; k < N; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

// --- Blocked Matrix Multiplication ---
// Uses tiling/blocking for better cache performance.
void matrix_mult_blocking(double** A, double** B, double** C, int N, int BLOCK_SIZE) {
    for (int i = 0; i < N; i += BLOCK_SIZE) {
        for (int j = 0; j < N; j += BLOCK_SIZE) {
            for (int k = 0; k < N; k += BLOCK_SIZE) {
                // Perform multiplication on the blocks
                for (int i1 = i; i1 < i + BLOCK_SIZE && i1 < N; ++i1) {
                    for (int j1 = j; j1 < j + BLOCK_SIZE && j1 < N; ++j1) {
                        double sum = C[i1][j1]; // Load previous value
                        for (int k1 = k; k1 < k + BLOCK_SIZE && k1 < N; ++k1) {
                            sum += A[i1][k1] * B[k1][j1];
                        }
                        C[i1][j1] = sum; // Store final value for the block
                    }
                }
            }
        }
    }
}


//parallel 'g++ -O{} matmul_block.cpp -o matmul_block{}.x' ::: 0 1 2 3 fast 

//parallel './matmul_block{1}.x 1024 {2} 10 >> data-{1}.txt' ::: 0 1 2 3 fast ::: 2 4 8 16 32 64 128 256 512 1024

//parallel ' sort -k 2 data-{1}.txt > data_{1}.txt' ::: 0 1 2 3 fast

//

