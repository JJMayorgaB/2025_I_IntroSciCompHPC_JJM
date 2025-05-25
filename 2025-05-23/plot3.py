import numpy as np
import matplotlib.pyplot as plt

data0 = np.loadtxt("datasorted_0.txt")
data1 = np.loadtxt("datasorted_1.txt")
data2 = np.loadtxt("datasorted_2.txt")
data3 = np.loadtxt("datasorted_3.txt")
datafast = np.loadtxt("datasorted_fast.txt")

fig, ax = plt.subplots()
ax.plot(data0[:, 0], data0[:, 1], label="Fib Opt 0")
ax.plot(data1[:, 0], data1[:, 1], label="Fib Opt 1")
ax.plot(data2[:, 0], data2[:, 1], label="Fib Opt 2")
ax.plot(data3[:, 0], data3[:, 1], label="Fib Opt 3")
ax.plot(datafast[:, 0], datafast[:, 1], label="Fib Opt fast")

ax.plot(data0[:, 0], data0[:, 2], label="FibFast Opt 0")
ax.plot(data1[:, 0], data1[:, 2], label="FibFast Opt 1")
ax.plot(data2[:, 0], data2[:, 2], label="FibFast Opt 2")
ax.plot(data3[:, 0], data3[:, 2], label="FibFast Opt 3")
ax.plot(datafast[:, 0], datafast[:, 2], label="FibFast Opt fast")

plt.xlabel("n")
plt.ylabel("Time")
plt.yscale("log")
#plt.xscale("log")
plt.grid(True)
plt.legend()
plt.savefig('blocking.pdf')
plt.show()