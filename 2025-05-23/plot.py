import pandas as pd 
import matplotlib.pyplot as plt 
import seaborn as sns

sns.set(style="whitegrid", context="notebook")

df0 = pd.read_csv("data-0.txt", sep="\s+", header=None, names=["N","blocksize","t"])
df1 = pd.read_csv("data-1.txt", sep="\s+", header=None, names=["N","blocksize","t"])
df2 = pd.read_csv("data-2.txt", sep="\s+", header=None, names=["N","blocksize","t"])
df3 = pd.read_csv("data-3.txt", sep="\s+", header=None, names=["N","blocksize","t"])
dff = pd.read_csv("data-fast.txt", sep="\s+", header=None, names=["N","blocksize","t"])

plt.figure(figsize=(8,5))
sns.lineplot(data=df0, x="blocksize",y="t", label="O0")
sns.lineplot(data=df0, x="blocksize",y="t", label="O1")
sns.lineplot(data=df0, x="blocksize",y="t", label="O2")
sns.lineplot(data=df0, x="blocksize",y="t", label="O3")
sns.lineplot(data=dff, x="blocksize",y="t", label="fast")

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




