#include <cstdio>
#include <cstdlib>
#include<chrono>
#include<iostream>
/*
  Tests cache misses.
*/

void option1(long * data, int m, int n);
void option2(long * data, int m, int n);
void option3(long * data, int m, int n);

int main(int argc, char **argv)
{
  if (argc < 3){
    printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
    return 1;
  }
  long sI = atoi(argv[1]);
  long sJ = atoi(argv[2]);

  //printf("Operating on matrix of size %ld by %ld\n", sI, sJ);

  long *arr = new long[sI*sJ]; // double array.

  // option 1
  auto start = std::chrono::steady_clock::now();
  option1(arr, sI, sJ);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed1 = end - start;
  
 // std::cout << (end1-start1).count() << "\n";  
  // option 2
  start = std::chrono::steady_clock::now();
  option2(arr, sI, sJ);
  end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed2 = end - start;
 // std::cout << (end2-start2).count() << "\n";
  
  // option 3
  start = std::chrono::steady_clock::now();
  option3(arr, sI, sJ);
  end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed3 = end - start;
 // std::cout << (end3-start3).count() << "\n";

  // why this?
  //printf("%ld\n", arr[0]);

  std::cout << sI << "\t" << elapsed1.count() << "\t" << elapsed2.count() << "\t" << elapsed3.count() << std::endl;

  // free memory
  delete [] arr; 

  return 0;
}



void option1(long * data, int m, int n)
{
  for (long i=0; i < m; ++i)
    for (long j=0; j < n; ++j)
      data[(i * (n)) + j ] = i;
}

void option2(long * data, int m, int n)
{
  for (long i=0; i < m; ++i)
    for (long j=0; j < n; ++j)
      data[(j * (m)) + i ] = i;
}

void option3(long * data, int m, int n)
{
  for (int i=0; i < m*n; ++i) data[i] = i;
}