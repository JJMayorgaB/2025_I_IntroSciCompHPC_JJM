#include <iostream>
#include <eigen3/Eigen/Dense>
#include<ctime>

int main(int argc, char **argv)
{   
    const int SEED = std::atoi(argv[1]);
    srand(SEED); // control seed

    const int N = std::atoi(argv[2]);

    Eigen::MatrixXd A = Eigen::MatrixXd::Random(N, N);
    Eigen::VectorXd b = Eigen::VectorXd::Random(N);

    //A << 1,2,3,  4,5,6,  7,8,10;
    //b << 3, 3, 4;

    //std::cout << "Here is the matrix A:\n" << A << std::endl;
    //std::cout << "Here is the vector b:\n" << b << std::endl;
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
    //std::cout << "The solution is:\n" << x << std::endl;
    std::cout << "Verification:\n" << (A*x - b).norm() << std::endl;
}