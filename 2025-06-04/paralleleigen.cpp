#include <iostream>
#include <eigen3/Eigen/Dense>
#include<ctime>
#include<chrono>

void stats(const int size, const int reps, // input parameters
               double & mean_wtime, long double & sigma_wtime, // output
               double & mean_ctime, double & sigma_ctime); // output

int main(int argc, char ** argv)
    {
      const int M = atoi(argv[1]); // Matrix size
      const int R = atoi(argv[2]); // Repetitions

      double mean_wtime;
      long double sigma_wtime;
      double mean_ctime, sigma_ctime;
      stats(M, R, mean_wtime, sigma_wtime, mean_ctime, sigma_ctime);
      std::cout << M
                << "\t" << mean_wtime << "\t" << sigma_wtime
                << "\t" << mean_ctime << "\t" << sigma_ctime
                << std::endl;
        
      return 0;
    }


void stats(const int size, const int reps,
               double & mean_wtime, long double & sigma_wtime,
               double & mean_ctime, double & sigma_ctime)
    {
        double suma_wtime = 0.0;
        double suma_wtime2 = 0.0;
        double suma_ctime = 0.0;
        double suma_ctime2 = 0.0;

        for(int ii = 0; ii < reps; ii++)
        {
            Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
            Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);

            auto start = std::chrono::steady_clock::now();
            const std::clock_t c_start = std::clock();

            Eigen::MatrixXd x = A.partialPivLu().solve(b);

            auto end = std::chrono::steady_clock::now();
            const std::clock_t c_end = std::clock();


            suma_wtime += (end-start).count();
            suma_wtime2 += ((end-start).count()*(end-start).count());

            suma_ctime += (c_end - c_start/CLOCKS_PER_SEC);
            suma_ctime2 += ((c_end - c_start/CLOCKS_PER_SEC)*(c_end - c_start/CLOCKS_PER_SEC));

            //añadir a suma wtime, suma wtime2
            std::cerr << x(0,0) << "\n";

        }

        mean_wtime = suma_wtime/reps;
        mean_ctime = suma_ctime/reps;

        sigma_wtime = std::sqrt(reps*(suma_wtime2/reps - mean_wtime*mean_wtime/(reps-1)));
        sigma_ctime = std::sqrt(reps*(suma_ctime2/reps - mean_ctime*mean_ctime/(reps-1)));
    }


/*
g++ -O3 -fopenmp -std=c++17 -fsanitize=undefined,leak,address paralleleigen.cpp 
 OMP_NUMTHREADS=4 /usr/bin/time ./a.out 2000
*/