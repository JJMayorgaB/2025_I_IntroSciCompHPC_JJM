#!/bin/bash

# Compilación con flags adicionales
echo "Compilando programa..."
g++ -std=c++17 -O3 -Wall -Wextra -Wno-unused-but-set-variable -fopenmp -ltbb -o parallel_metrics.x parallel.cpp

# Verificar que la compilación fue exitosa
if [ $? -ne 0 ]; then
    echo "Error en la compilación"
    exit 1
fi

# Limpiar datos anteriores
echo "Limpiando archivos anteriores..."
rm -f *.txt

# Configuración
VECTOR_SIZE=200000000
MAX_THREADS=17

echo "Ejecutando pruebas..."
echo "Tamaño de vector: $VECTOR_SIZE"
echo "Máximo número de threads: $MAX_THREADS"
echo

# Ejecutar para cada política (0=seq, 1=par, 2=par_unseq, 3=openmp)
for policy in 0 1 2; do
    echo "Ejecutando política $policy..."
    
    # Ejecutar para cada número de threads
    for threads in $(seq 1 $MAX_THREADS); do
        echo -n "  Threads: $threads ... "
        
        # Ejecutar el programa y agregar resultado al archivo correspondiente
        ./parallel_metrics.x $VECTOR_SIZE $threads $policy >> "data_${policy}.txt"
        
        # Verificar que la ejecución fue exitosa
        if [ $? -eq 0 ]; then
            echo "OK"
        else
            echo "ERROR"
        fi
    done
    echo
done

echo "Ordenando archivos de datos..."
# Ordenar cada archivo individualmente por la primera columna (threads)
for policy in 0 1 2; do
    if [[ -f "data_${policy}.txt" ]]; then
        sort -nk 1 "data_${policy}.txt" > "data_${policy}_sorted.txt"
        rm "data_${policy}.txt"
        echo "Archivo data_${policy}_sorted.txt creado"
    else
        echo "Warning: data_${policy}.txt no existe"
    fi
done

# Limpiar ejecutables
echo "Limpiando ejecutables..."
rm -f *.x

# Ejecutar visualización
echo "Generando gráficas..."
if command -v python3 &> /dev/null; then
    python3 parallel_graphs.py
elif command -v python &> /dev/null; then
    python parallel_graphs.py
else
    echo "Python no encontrado. Ejecuta manualmente: python parallel_graphs.py"
fi

echo "¡Proceso completado!"