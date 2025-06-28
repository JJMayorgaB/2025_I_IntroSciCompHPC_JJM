#Este comando de bash tiene como objetivo calcular las metricas paralelas con
#parallel_metric.cpp y graficarlas mediante parallel_graphs.py

#Se realiza la compilación 
g++ -std=c++17 -O3 -Wall -Wextra -fopenmp -o parallel_metrics.x parallel_metrics.cpp

#Se eliminan datos anteriores
rm *.txt

# Se ejecuta el programa y se guardan los datos
# Uso de GNU Parallel para probar threads {1..17} y políticas {0,1,2}
parallel './parallel_metrics.x 200000000 {1} {2} >> data_{2}.txt' ::: {1..17} ::: 0 1 2

# Ordenar cada archivo individualmente por la primera columna (threads)
for policy in 0 1 2; do
    if [[ -f "data_${policy}.txt" ]]; then
        sort -nk 1 "data_${policy}.txt" > "data_${policy}_sorted.txt"
        rm data_${policy}.txt
    else
        echo "Error: data_${policy}.txt no existe."
    fi
done

#Eliminamos todos los ejecutables para mantener un entorno limpio
rm *.x

#Graficamos 
python parallel_graphs.py