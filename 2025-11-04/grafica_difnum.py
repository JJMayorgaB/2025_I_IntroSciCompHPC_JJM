import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc

# Configurar estilo LaTeX
rc('text', usetex=True)
rc('font', family='serif', size=12)

# Leer datos del archivo (asumiendo formato: k sum1 sum2 error)
data = np.loadtxt('data.txt')  
k = data[:, 0]
error = data[:, 3]

# Crear figura
plt.figure(figsize=(8, 6))
plt.plot(k, error, 'ro-', markersize=2, label=r'$|1 - \frac{\mathrm{sum}_1(k)}{\mathrm{sum}_2(k)}|$')

# Añadir línea horizontal en épsilon de máquina para float (1.19e-7)
plt.axhline(y=1.19e-7, color='blue', linestyle='--', linewidth=1, label=r'$\epsilon_{\mathrm{float}}$')

# Detalles del gráfico
plt.xlabel(r'$N$', fontsize=14)
plt.ylabel(r'Error relativo $\Delta$', fontsize=14)
plt.title(r'Error entre $\mathrm{sum}_1(N)$ y $\mathrm{sum}_2(N)$', fontsize=16)
plt.yscale('log')  # Escala logarítmica para mejor visualización
plt.grid(True, which='both', linestyle='--', alpha=0.5)
plt.legend()
plt.tight_layout()

# Guardar figura
plt.savefig('error_plot.pdf', format='pdf', bbox_inches='tight')
plt.show()