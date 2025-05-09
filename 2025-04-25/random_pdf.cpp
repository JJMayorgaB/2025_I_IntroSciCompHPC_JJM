//Para ejecutar este codigo recomiendo el orden
// g++ random_pdf.cpp -o random_pdf -std=c++11
// .\random_pdf.exe 1 5000 3.5 0.4 2.7 4.6 50 > datos1.txt
// Para obtener por ejemplo los datos de la semilla 1. Despues graficar con su herramienta de elección.


#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{

  // Verificar que se proporcionan suficientes argumentos
  if (argc < 8) {
    std::cerr << "Uso: " << argv[0] << " SEED NSAMPLES MU SIGMA XMIN XMAX NBINS" << std::endl;
    return 1;
  }

  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]); // Se cambio atoi por atof ya que MU es double  
  const double SIGMA = std::atof(argv[4]);  // Se cambio atoi por atof ya que SIGMA es double  
  const double XMIN = std::atof(argv[5]); // Se cambio atoi por atof ya que XMIN es double  
  const double XMAX = std::atof(argv[6]); // Se cambio atoi por atof ya que XMAX es double       
  const int NBINS = std::atoi(argv[7]);
  
  // Verificaciones adicionales en caso de presentar parámetros incorrectos
  if (NSAMPLES <= 0 || NBINS <= 0 || SIGMA <= 0 || XMIN >= XMAX) {
    std::cerr << "Error en los parámetros: verifica que NSAMPLES > 0, NBINS > 0, SIGMA > 0 y XMIN < XMAX" << std::endl;
    return 1;
  }

  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};

  std::vector<int> histograma(nbins, 0);

  double ancho_caja = (xmax - xmin) / nbins;
  int elementos = 0;

  for(int n = 0; n < nsamples; ++n) {
    
    double r = dis(gen);

    if (r >= xmin && r <= xmax) {

      int bin = std::floor((r - xmin) / ancho_caja);

      //Si entra en el caso limite de xmax entra en el ultimo bin
      if (bin >= nbins){

        bin = nbins - 1;

      }

      histograma[bin]++;
      elementos++;

    }

  }
  
  for(int i = 0; i < nbins; ++i) {

    double x = xmin + (i + 0.5) * ancho_caja; // centro del bin
    double pdf = static_cast<double>(histograma[i]) / (elementos * ancho_caja); //Normalizamos la PDF para que este en 1
    
    std::cout << x << "\t" << pdf << "\n"; //Salida de los datos

  }

}