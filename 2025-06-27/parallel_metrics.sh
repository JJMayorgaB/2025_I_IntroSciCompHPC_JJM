#!/bin/bash

EXEC="./program"
OUTPUT="data.txt"
VECTOR_SIZE=200000000

echo "Compilando programa..."
g++ -std=c++17 -O3 -fsanitize=thread -fopenmp -g parallel.cpp -o $EXEC || exit 1

echo "Threads Modo Tiempo(s)" > $OUTPUT  # Cabecera con espacios

for modo in {0..2}; do
    for threads in {1..17}; do
        echo "Ejecutando modo $modo con $threads threads..."
        result=$($EXEC $VECTOR_SIZE $threads $modo 2>&1)
        echo "$threads $modo $result" >> $OUTPUT  # Datos con espacios
    done
done

echo "Resultados guardados en $OUTPUT"

python parallel_graph.py