import numpy as np
import matplotlib.pyplot as plt

# Cargar los datos
data0 = np.loadtxt("datasorted_0.txt")
data1 = np.loadtxt("datasorted_1.txt")
data2 = np.loadtxt("datasorted_2.txt")
data3 = np.loadtxt("datasorted_3.txt")
datafast = np.loadtxt("datasorted_fast.txt")

# Obtener los valores de referencia (n=20)
time20 = data0[3, 1]  # Tiempo fib lento para n=20 (asumiendo que n=20 está en la 4ta fila)
time20fast = data0[3, 2]  # Tiempo fib rápido para n=20

# Normalizar los datos
def normalize_data(data, ref_slow, ref_fast):
    data_norm = data.copy()
    data_norm[:, 1] = data[:, 1] / ref_slow  # Columna 2 (fib lento) normalizada
    data_norm[:, 2] = data[:, 2] / ref_fast  # Columna 3 (fib rápido) normalizada
    return data_norm

data0_norm = normalize_data(data0, time20, time20fast)
data1_norm = normalize_data(data1, time20, time20fast)
data2_norm = normalize_data(data2, time20, time20fast)
data3_norm = normalize_data(data3, time20, time20fast)
datafast_norm = normalize_data(datafast, time20, time20fast)

# Crear la figura
fig, ax = plt.subplots()

# Graficar datos normalizados (fib lento)
ax.plot(data0_norm[:, 0], data0_norm[:, 1], label="Fib Opt 0")
ax.plot(data1_norm[:, 0], data1_norm[:, 1], label="Fib Opt 1")
ax.plot(data2_norm[:, 0], data2_norm[:, 1], label="Fib Opt 2")
ax.plot(data3_norm[:, 0], data3_norm[:, 1], label="Fib Opt 3")
ax.plot(datafast_norm[:, 0], datafast_norm[:, 1], label="Fib Opt fast")

# Graficar datos normalizados (fib rápido)
ax.plot(data0_norm[:, 0], data0_norm[:, 2], "--", label="FibFast Opt 0")
ax.plot(data1_norm[:, 0], data1_norm[:, 2], "--", label="FibFast Opt 1")
ax.plot(data2_norm[:, 0], data2_norm[:, 2], "--", label="FibFast Opt 2")
ax.plot(data3_norm[:, 0], data3_norm[:, 2], "--", label="FibFast Opt 3")
ax.plot(datafast_norm[:, 0], datafast_norm[:, 2], "--", label="FibFast Opt fast")

plt.xlabel("n")
plt.ylabel("Normalized Time (relative to n=20)")
plt.yscale("log")
plt.grid(True)
plt.legend()
plt.savefig('normalized_times.pdf')
plt.show()