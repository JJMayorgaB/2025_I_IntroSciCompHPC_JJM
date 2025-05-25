#Se realiza la compilación para cada nivel de optimización
parallel 'g++ -O{} basic_optimization.cpp -o basic_optimization{}.x' ::: 0 1 2 3 fast

#Se ejecuta el programa y se guardan los datos
parallel './basic_optimization{1}.x {2} >> data-{1}.txt' ::: 0 1 2 3 fast ::: {5..50..5}

#En caso de que la salida de los datos no se de ordenadamente, ordenamos los datos
for level in 0 1 2 3 fast; do
    if [[ -f "data-$level.txt" ]]; then
        sort -nk 1 data-$level.txt > datasorted_$level.txt;
        rm data-$level.txt
    else
        echo "Error: data-$level.txt no existe."
    fi
done

#Eliminamos todos los ejecutables para mantener un entorno limpio
rm *.x