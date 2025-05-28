import numpy as np
import matplotlib.pyplot as plt

# Cargar los datos
data = np.loadtxt("datasorted.txt")

# Crear la figura
fig, ax = plt.subplots()

ax.plot(data[:, 0], data[:, 1], label="Option 1")
ax.plot(data[:, 0], data[:, 2], label="Option 2")
ax.plot(data[:, 0], data[:, 3], label="Option 3")


plt.xlabel("Matrix size n")
plt.ylabel("Time")
#plt.xscale("log")
plt.grid(True)
plt.legend()
plt.savefig('matrixtime.pdf')
plt.show()