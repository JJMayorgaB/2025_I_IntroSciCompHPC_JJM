# Compila los ejecutables en los diferentes niveles de optimización
parallel 'g++ -O{} fibo.cpp -o {}.x' ::: 0 1 2 3 fast

# Limite máximo de n que se va a trabajar
MAX=40;

# Iteración para calcular el tiempo de ejecución para diferentes n y guardarlos en archivos .txt
for ((n = 5; n <= MAX; n += 5)); do
    parallel './{}.x '"$n"' >> {}.txt' ::: 0 1 2 3 fast;
done

# Obtener tiempo base con fib(20) -O0 para normalizar la gráfica
t_normal=$(awk '$1 == 20 {print $2}' 0.txt)

# Normalizar los datos y guardarlos
for opt in 0 1 2 3 fast; do
    awk -v normal="$t_normal" '{printf "%d\t%f\t%f\n", $1, $2/normal, $3/normal}' $opt.txt > norm_$opt.txt
done

# Grafíca y guarda directamente los resultados en un archivo pdf, para visualizar abrir el archivo que se creó "Resultados_Fibo nacci.pdf"
gnuplot << EOF
set terminal pdfcairo size 15in,10in enhanced font 'Times New Roman,30'
set output 'Resultados_Fibonacci.pdf'
set title 'Comparación de tiempo Sucesión Fibonacci: recursivo vs rapido'
set xlabel 'n'
set ylabel 'Tiempo (s)'
set logscale y
set grid
set key top left

plot \
    'norm_0.txt' u 1:2 w lp lc rgb "red" dt 5 title '-O0 recursivo', \
    'norm_1.txt' u 1:2 w lp lc rgb "orange" dt 5 title '-O1 recursivo', \
    'norm_2.txt' u 1:2 w lp lc rgb "green" dt 5 title '-O2 recursivo', \
    'norm_3.txt' u 1:2 w lp lc rgb "blue" dt 5 title '-O3 recursivo', \
    'norm_fast.txt' u 1:2 w lp lc rgb "violet" dt 5 title '-Ofast recursivo', \
    'norm_0.txt' u 1:3 w lp lc rgb "red" title '-O0 rapido', \
    'norm_1.txt' u 1:3 w lp lc rgb "orange" title '-O1 rapido', \
    'norm_2.txt' u 1:3 w lp lc rgb "green" title '-O2 rapido', \
    'norm_3.txt' u 1:3 w lp lc rgb "blue" title '-O3 rapido', \
    'norm_fast.txt' u 1:3 w lp lc rgb "violet" title '-Ofast rapido'

EOF