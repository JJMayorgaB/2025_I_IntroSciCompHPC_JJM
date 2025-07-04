import pandas as pd
import matplotlib.pyplot as plt

# Leer los datos con nombres de columna apropiados
df = pd.read_csv("parallel_results_slurm.txt", sep='\s+', names=['Threads', 'Tiempo'])

# Obtener tiempo secuencial base (con 1 hilo)
tiempo_base = df[df["Threads"] == 1]["Tiempo"].iloc[0]

# Calcular speedup y eficiencia
df["speedup"] = tiempo_base / df["Tiempo"]
df["eficiencia"] = df["speedup"] / df["Threads"]

# --- Gráfica de Speedup ---
plt.figure(figsize=(10, 6))
plt.plot(df["Threads"], df["speedup"], marker='o', linewidth=2, markersize=8, label="Speedup real")
plt.plot(df["Threads"], df["Threads"], '--', label="Speedup teórico (ideal)", alpha=0.7)
plt.title("Parallel Speedup vs Número de Threads")
plt.xlabel("Número de threads")
plt.ylabel("Parallel Speedup")
plt.grid(True, alpha=0.3)
plt.legend()
plt.tight_layout()
plt.savefig("speedup.pdf")
plt.show()

# --- Gráfica de Eficiencia ---
plt.figure(figsize=(10, 6))
plt.plot(df["Threads"], df["eficiencia"], marker='s', linewidth=2, markersize=8, label="Eficiencia real")
plt.axhline(y=1, color='r', linestyle='--', alpha=0.7, label="Eficiencia ideal (1.0)")
plt.axhline(y=0.6, color='orange', linestyle='--', alpha=0.7, label="Umbral aceptable (0.6)")
plt.title("Eficiencia Paralela vs Número de Threads")
plt.xlabel("Número de threads")
plt.ylabel("Eficiencia Paralela")
plt.grid(True, alpha=0.3)
plt.legend()
plt.tight_layout()
plt.savefig("efficiency.pdf")
plt.show()

