g++ -std=c++17 -fopenmp -O3 -fsanitize=undefined,leak,address lu.cpp

for n in 1 2 4 8 12; do 
MSIZE=2500
    for ((ii=250; ii <= $MSIZE; ii +=250)); do 
        echo -n $n $ii " ";  
        OMP_NUM_THREADS=n ./a.out $ii 4 2>/dev/null 1>> data-$n.txt;
    done 
done

python plot2.py

rm a.out *.txt