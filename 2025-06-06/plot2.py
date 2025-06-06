import numpy as np
import matplotlib.pyplot as plt
import re

def graficar_multiples_archivos(lista_archivos):
    plt.figure(figsize=(10, 6))

    colores = ['blue', 'red', 'green', 'orange', 'purple']
    estilos = ['-', '-', '-', '-', '-']

    for i, archivo in enumerate(lista_archivos):
        datos = np.loadtxt(archivo)
        x = datos[:, 0]
        y1 = datos[:, 1]
        erry1 = datos[:, 2]
        y2 = datos[:, 3]
        erry2 = datos[:, 4]

        color = colores[i % len(colores)]

        # Extraer número de threads desde el nombre del archivo
        match = re.search(r"data-(\d+)\.txt", archivo)
        n_threads = match.group(1) if match else f"? ({archivo})"

        # Etiquetas con número de threads
        plt.errorbar(x, y1, yerr=erry1, fmt='o', linestyle="-", color=color,
                     capsize=4, label=f'Wall Time - {n_threads} threads')
        plt.errorbar(x, y2, yerr=erry2, fmt='s', linestyle="-.", color=color,
                     capsize=4, label=f'CPU Time - {n_threads} threads')

    # Estética del gráfico
    plt.xlabel("Tamaño de matriz")
    plt.ylabel("Tiempo")
    plt.title("Tiempo de ejecución para distintos threads")
    plt.yscale("log")
    plt.xscale("log")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

# Ejemplo de uso
archivos = ["data-1.txt", "data-2.txt", "data-4.txt", "data-8.txt", "data-12.txt"]
graficar_multiples_archivos(archivos)