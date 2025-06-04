    #include <iostream>
    #include <chrono>
    #include <ctime>
    #include <cmath>
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
      double wsum = 0, wsum2 = 0, csum = 0, csum2 = 0;
      double wtime = 0, ctime = 0;
// TODO
      std::cout << M
          << "\t" << mean_wtime << "\t" << sigma_wtime
          << "\t" << mean_ctime << "\t" << sigma_ctime
          << std::endl;
    }