import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc

rc('text', usetex=True)
rc('font', family='serif', size=12)

data = np.loadtxt('data1_000_000.txt', encoding='utf-16')  
k = data[:, 0]
error = data[:, 3]

plt.figure(figsize=(8, 6))
plt.plot(k, error, 'ro', markersize=1, label=r'$|1 - \frac{\mathrm{sum}_1(k)}{\mathrm{sum}_2(k)}|$')

plt.xlabel(r'$N$', fontsize=14)
plt.ylabel(r'Error relativo $\Delta$', fontsize=14)
plt.title(r'Error entre $\mathrm{sum}_1(N)$ y $\mathrm{sum}_2(N)$', fontsize=16)
#plt.yscale('log') 
#plt.xscale('log') 
plt.grid(True, which='both', linestyle='--', alpha=0.5)
plt.legend()
plt.tight_layout()

plt.savefig('error_plot.pdf', format='pdf', bbox_inches='tight')
plt.show()


