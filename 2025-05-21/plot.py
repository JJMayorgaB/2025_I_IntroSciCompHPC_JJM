import pandas as pd 
import matplotlib.pyplot as plt 
import seaborn as sns

sns.set(style="whitegrid", context="notebook")

df0 = pd.read_csv("data-0.txt", sep="\s+", header=None, names=["MSIZE","csize","t1","t2"])
df1 = pd.read_csv("data-1.txt", sep="\s+", header=None, names=["MSIZE","csize","t1","t2"])
df2 = pd.read_csv("data-2.txt", sep="\s+", header=None, names=["MSIZE","csize","t1","t2"])
df3 = pd.read_csv("data-3.txt", sep="\s+", header=None, names=["MSIZE","csize","t1","t2"])

plt.figure(figsize=(8,5))
sns.lineplot(data=df0, x="csize",y="t2", label="O0")
sns.lineplot(data=df1, x="csize",y="t2", label="O1")
sns.lineplot(data=df2, x="csize",y="t2", label="O2")
sns.lineplot(data=df3, x="csize",y="t2", label="O3")
#plt.yscale("log")
plt.xscale("log")
plt.xlabel("csize")
plt.ylabel(r"t2")
#plt.title("Diferencia relativa entre las sumas en función N")
plt.grid(True)
plt.tight_layout()
plt.legend()
plt.savefig('blocking.pdf')
plt.show()






