parallel 'g++ -O{} fibo.cpp -o {}.x' ::: 1 2 3 fast
parallel './{1}.x {2} >> {1}.txt' ::: 1 2 3 fast ::: 2 4 8 16 