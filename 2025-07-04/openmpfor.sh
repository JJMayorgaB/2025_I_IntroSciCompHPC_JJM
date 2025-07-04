#!/bin/bash

#SBATCH --job-name=parallel_metrics     # Job name
#SBATCH --output=slurm_parallel_%j.out # Standard output and error log
#SBATCH --error=slurm_parallel_%j.err  # %j is replaced with the job ID
#SBATCH --nodes=1                  # Request 1 node
#SBATCH --ntasks=1                 # Request 1 task (your OpenMP program is a single task)
#SBATCH --cpus-per-task=16         # Request 8 CPUs for this task (adjust as needed for your program)
#SBATCH --time=00:10:00            # Wall-clock time limit (HH:MM:SS)
#SBATCH --mem=4G                   # Memory per node (adjust as needed)

# Variables
EXEC="parallelfor.x"
VECTOR_SIZE=1000000
OUTPUT="parallel_results_slurm.txt"

echo "Compiling OpenMP program"
g++ -std=c++17 -g -fopenmp openmpfor.cpp -o $EXEC || exit 1

echo "Starting OpenMP job on node: $(hostname)"
echo "Number of requested CPUs per task: $SLURM_CPUS_PER_TASK"

#Limpiar archivos previos
rm -f $OUTPUT *.pdf

# Set the number of OpenMP threads
# This should ideally be equal to --cpus-per-task for optimal performance
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

# Ejecutar con diferentes números de threads
max_threads=$((SLURM_CPUS_PER_TASK + 1))
for threads in $(seq 1 $max_threads); do
    echo "Ejecutando con $threads threads..."
    export OMP_NUM_THREADS=$threads
    result=$(./$EXEC $VECTOR_SIZE 2>&1)
    echo "$threads $result" >> $OUTPUT
done

echo "OpenMP job finished."
echo "Resultados guardados en $OUTPUT"

echo "Generating graphs from output data"
python graphs.py
