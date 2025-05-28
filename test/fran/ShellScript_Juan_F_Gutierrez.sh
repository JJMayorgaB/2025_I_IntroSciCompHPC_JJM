N=50
for opt in {0,1,2,3,fast}
  do
    g++ -O$opt Fibonacci.cpp -o fib.x
    

    parallel -j 4 "./fib.x {} >> Opt$opt.txt" ::: $(seq 1 $N)

  done
