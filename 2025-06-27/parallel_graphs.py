import numpy as np
import matplotlib.pyplot as plt

def graficar_speedup_efficiency(lista_archivos):
    # Configuración de estilos y colores
    colores = ['blue', 'red', 'green']
    politicas = ['Secuencial (seq)', 'Paralelo (par)', 'Paralelo no secuencial (par_unseq)']
    
    # Crear dos figuras (una para speedup, otra para efficiency)
    fig1, ax1 = plt.subplots(figsize=(10, 6))
    fig2, ax2 = plt.subplots(figsize=(10, 6))
    
    for i, archivo in enumerate(lista_archivos):
        # Leer datos (ignorando líneas vacías o comentarios)
        datos = np.loadtxt(archivo)
        threads = datos[:, 0]  # Primera columna: número de threads
        speedup = datos[:, 1]  # Segunda columna: speedup
        efficiency = datos[:, 2]  # Tercera columna: efficiency
        
        # Gráfica de Speedup
        ax1.plot(threads, speedup, 
                 marker='o', 
                 linestyle='-', 
                 color=colores[i], 
                 label=politicas[i])
        
        # Gráfica de Efficiency
        ax2.plot(threads, efficiency, 
                 marker='s', 
                 linestyle='--', 
                 color=colores[i], 
                 label=politicas[i])
    
    # ---- Añadir curva teórica y=x al gráfico de Speedup ----
    max_threads = max([np.loadtxt(archivo)[:, 0].max() for archivo in lista_archivos])
    x_teorico = np.linspace(1, max_threads, 100)
    y_teorico = x_teorico  # Speedup ideal (y = x)
    
    ax1.plot(x_teorico, y_teorico, 
             color='black', 
             linestyle=':', 
             linewidth=1,
             label='Speedup Teórico')
    
    # Ajustes para la gráfica de Speedup
    ax1.set_xlabel("Número de Threads")
    ax1.set_ylabel("Parallel Speedup")
    ax1.set_title("Parallel Speedup vs Número de Threads (8 cores físicos / 16 threads)")
    ax1.legend()
    ax1.grid(True)
    ax1.axhline(y=1, color='gray', linestyle=':', alpha=0.5)  # Línea de referencia
    
    # Ajustes para la gráfica de Efficiency
    ax2.set_xlabel("Número de Threads")
    ax2.set_ylabel("Eficiencia Paralela")
    ax2.set_title("Eficiencia Paralela vs Número de Threads (8 cores físicos / 16 threads)")
    ax2.legend()
    ax2.grid(True)
    ax2.axhline(y=100, color='gray', linestyle=':', alpha=0.5)  # Línea de referencia (100%)
    
    plt.tight_layout()
    fig1.savefig("speedup.pdf")
    fig2.savefig("efficiency.pdf")
    plt.show()

# Archivos a graficar (asegúrate de que los nombres coincidan)
archivos = ["data_0_sorted.txt", "data_1_sorted.txt", "data_2_sorted.txt"]
graficar_speedup_efficiency(archivos)