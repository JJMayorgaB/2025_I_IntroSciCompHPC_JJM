import numpy as np
import matplotlib.pyplot as plt

data0 = np.loadtxt("data-0.txt")
data1 = np.loadtxt("data-1.txt")
data2 = np.loadtxt("data-2.txt")
data3 = np.loadtxt("data-3.txt")
datafast = np.loadtxt("data-fast.txt")

fig, ax = plt.subplots()
ax.plot(data0[:, 1], data0[:, 2], label="Optimizer 0")
ax.plot(data1[:, 1], data1[:, 2], label="Optimizer 1")
ax.plot(data2[:, 1], data2[:, 2], label="Optimizer 2")
ax.plot(data3[:, 1], data3[:, 2], label="Optimizer 3")
ax.plot(datafast[:, 1], datafast[:, 2], label="Optimizer fast")

plt.xlabel("Blocksize")
plt.ylabel("Time")
plt.xscale("log")
plt.grid(True)
plt.legend()
plt.savefig('blocking.pdf')
plt.show()