NMAX = 12

for nthreads in 1 2 4 8 12; do
    FNAME="datos_${nthreads}.txt"
    echo > $FNAME
    JOBS=$(echo $NMAX/$nthreads | bc)
    echo $nthreads
    echo $JOBS
    parallel -j $JOBS 'OMP_NUM_THREADS='$nthreads' ./a.out {1} 2 '${nthreads}1 1>> '${FNAME}' 2>/dev/null' ::: {250..2500..250}