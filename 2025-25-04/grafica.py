import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc

rc('text', usetex=True)
rc('font', family='serif', size=12)

plt.figure(figsize=(8, 6))
plt.grid(True)
plt.xlabel(r'Valor $x$', fontsize=14)
plt.ylabel(r'Densidad de probabilidad', fontsize=14)
plt.title(r'Comparación de distribuciones normales generadas aleatoriamente', fontsize=16)

# Parámetros comunes (ajusta según tus necesidades)
media = 3.5
desviacion = 0.4
x_min, x_max = 2.7, 4.6

# Colores y etiquetas para cada dataset
archivos = ['datos1.txt', 'datos2.txt', 'datos3.txt']
colores = ['b', 'g', 'c']
labels = [r'Semilla 1', r'Semilla 2', r'Semilla 5']

# Leer y graficar cada archivo
for archivo, color, label in zip(archivos, colores, labels):
    try:
        x, pdf = [], []
        with open(archivo, 'r', encoding='utf-16') as f:
            for linea in f:
                valores = linea.strip().split()
                if len(valores) == 2:
                    x.append(float(valores[0]))
                    pdf.append(float(valores[1]))
        
        plt.plot(x, pdf, color+'.', linewidth=1.5, alpha=0.7, label=label)
    
    except FileNotFoundError:
        print(f"¡Advertencia! Archivo {archivo} no encontrado. Saltando...")
        continue

# Curva teórica común
x_teorico = np.linspace(x_min, x_max, 500)
pdf_teorico = (1/(desviacion*np.sqrt(2*np.pi))) * np.exp(-0.5*((x_teorico-media)/desviacion)**2)
plt.plot(x_teorico, pdf_teorico, 'r--', linewidth=2, label=r'Curva teórica')

# Ajustes finales
plt.legend()
plt.tight_layout()

# Guardar y mostrar
plt.savefig('random_pdf.pdf')
plt.show()