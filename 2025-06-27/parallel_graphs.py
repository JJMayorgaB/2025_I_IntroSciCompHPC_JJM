import pandas as pd
import matplotlib.pyplot as plt

# Leer los datos
df = pd.read_csv("data.txt", delim_whitespace=True)

# Obtener tiempo secuencial base por modo (con 1 hilo)
tiempos_base = df[df["Threads"] == 1].set_index("Modo")["Tiempo(s)"].to_dict()

# Calcular speedup y eficiencia
df["speedup"] = df.apply(lambda row: tiempos_base[row["Modo"]] / row["Tiempo(s)"], axis=1)
df["eficiencia"] = df["speedup"] / df["Threads"]

# Modos disponibles
modos = df["Modo"].unique()
label = ["seq", "par", "par_unseq"]

# --- Gráfica de Speedup ---
plt.figure(figsize=(8, 5))
for modo in modos:
    datos = df[df["Modo"] == modo]
    plt.plot(datos["Threads"], datos["speedup"], marker='o', label=label[modo])

plt.plot(datos["Threads"], datos["Threads"], label="Speedup teórico")
plt.title("Parallel Speedup vs Número de Threads (8 cores físicos / 16 threads)")
plt.xlabel("Número de threads")
plt.ylabel("Parallel Speedup")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("speedup.pdf")
plt.show()

# --- Gráfica de Eficiencia ---
plt.figure(figsize=(8, 5))
for modo in modos:
    datos = df[df["Modo"] == modo]
    plt.plot(datos["Threads"], datos["eficiencia"], marker='s', label=label[modo])

plt.title("Eficiencia Paralela vs Número de Threads (8 cores físicos / 16 threads)")
plt.plot((1,17), (1,1), label="1")
plt.plot((1,17), (0.6,0.6), label="0.6")
plt.xlabel("Número de threads")
plt.ylabel("Eficiencia Paralela")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("efficiency.pdf")
plt.show()