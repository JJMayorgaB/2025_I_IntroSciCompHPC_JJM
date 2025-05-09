#include <random>
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    const int seed = std::atoi(argv[1]);
    const int nsamples = std::atoi(argv[2]);

    std::mt19937 gen(seed);
    std::normal_distribution<> dis{1.5, 0.3};
    for(int n = 0; n < nsamples; ++n) {
        std::cout << dis(gen) << std::endl;
    }
}