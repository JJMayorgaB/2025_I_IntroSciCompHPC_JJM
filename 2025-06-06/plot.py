import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
import pandas as pd

# Paleta de colores consistente
palette = sns.color_palette("Set2")

# Leer los datos
df1 = pd.read_csv("data-1.txt", sep="\s+", header=None, names=["N", "R", "t_w", "dev_w", "t_pc", "dev_pc"])
df2 = pd.read_csv("data-2.txt", sep="\s+", header=None, names=["N", "R", "t_w", "dev_w", "t_pc", "dev_pc"])
df4 = pd.read_csv("data-4.txt", sep="\s+", header=None, names=["N", "R", "t_w", "dev_w", "t_pc", "dev_pc"])
df8 = pd.read_csv("data-8.txt", sep="\s+", header=None, names=["N", "R", "t_w", "dev_w", "t_pc", "dev_pc"])
df12 = pd.read_csv("data-12.txt", sep="\s+", header=None, names=["N", "R", "t_w", "dev_w", "t_pc", "dev_pc"])


# Crear figura y ejes
fig, ax = plt.subplots()

# Graficar fib(n) con líneas sólidas y etiquetas
sns.lineplot(data=df1, x="N", y="t_w", label="1 thread", color=palette[0], linestyle='-', ax=ax)
ax.errorbar(data=df1, y="t_w", yerr="dev_w")
sns.lineplot(data=df2, x="N", y="t_w", label="2 threads", color=palette[1], linestyle='-', ax=ax)
sns.lineplot(data=df4, x="N", y="t_w", label="4 threads", color=palette[2], linestyle='-', ax=ax)
sns.lineplot(data=df8, x="N", y="t_w", label="8 threads", color=palette[3], linestyle='-', ax=ax)
sns.lineplot(data=df12, x="N", y="t_w", label="12 threads", color=palette[4], linestyle='-', ax=ax)

# Graficar fib_fast(n) con líneas punteadas (sin etiqueta para no duplicar leyenda)
sns.lineplot(data=df1, x="N", y="t_pc", label="1 thread", color=palette[0], linestyle='--', ax=ax)
sns.lineplot(data=df2, x="N", y="t_pc", label="2 threads", color=palette[1], linestyle='--', ax=ax)
sns.lineplot(data=df4, x="N", y="t_pc", label="4 threads", color=palette[2], linestyle='--', ax=ax)
sns.lineplot(data=df8, x="N", y="t_pc", label="8 threads", color=palette[3], linestyle='--', ax=ax)
sns.lineplot(data=df12, x="N", y="t_pc", label="12 threads", color=palette[4], linestyle='--', ax=ax)

# Leyenda 1: optimizaciones (por color)
legend1 = ax.legend(title="Threads", loc="upper left")

# Leyenda 2: tipo de función (por estilo de línea)
legend2_lines = [
    Line2D([0], [0], color='black', linestyle='--', label='t_pc'),
    Line2D([0], [0], color='black', linestyle='-', label='t_w')
]
legend2 = ax.legend(handles=legend2_lines, title="Tiempo", loc="lower right")

# Agregar la leyenda principal de nuevo (para que no se sobreescriba)
ax.add_artist(legend1)

# Resto del gráfico
ax.set_yscale("log")
ax.set_xlabel("n")
ax.set_ylabel("t")
ax.set_title("Comparación entre t_pc y t_w para distinto número de threads")
ax.grid(True)

plt.tight_layout()
plt.show()

