#include <iostream>
#include <eigen3/Eigen/Dense>

void stats(const int size, const int reps, // input parameters
               double & mean_wtime, double & sigma_wtime, // output
               double & mean_ctime, double & sigma_ctime); // output

int main(int argc, char ** argv)
    {
      const int M = atoi(argv[1]); // Matrix size
      const int R = atoi(argv[2]); // Repetitions

      double mean_wtime, sigma_wtime;
      double mean_ctime, sigma_ctime;
      stats(M, R, mean_wtime, sigma_wtime, mean_ctime, sigma_ctime);
      std::cout << M
                << "\t" << mean_wtime << "\t" << sigma_wtime
                << "\t" << mean_ctime << "\t" << sigma_ctime
                << std::endl;
        
      return 0;
    }


void stats(const int size, const int reps,
               double & mean_wtime, double & sigma_wtime,
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


            Eigen::MatrixXd x = A.partialPivLu().solve(b);

            //añadir a suma wtime, suma wtime2
            std::cerr << x(0,0) << "\n";


        }

        double mean_wtime = suma_wtime/reps;
        double mean_ctime = suma_ctime/reps;

        double sigma_wtime = std::sqrt(reps*(suma_wtime2/reps - mean_wtime*mean_wtime/(reps-1)));
        double sigma_c
        time = std::sqrt(reps*(suma_ctime2/reps - mean_ctime*mean_ctime/(reps-1)));



        /*
         -Definir variables para sumar los tiempos
         -Llamar/copiar codigo reps veces a solvesystem y medir su tiempo
         -Calcular las estadisticas y reornar/guardar valores
        */


        std::cout << M
            << "\t" << mean_wtime << "\t" << sigma_wtime
            << "\t" << mean_ctime << "\t" << sigma_ctime
            << std::endl;
    }


/*
g++ -O3 -fopenmp -std=c++17 -fsanitize=undefined,leak,address paralleleigen.cpp 
 OMP_NUMTHREADS=4 /usr/bin/time ./a.out 2000
*/