import matplotlib.pyplot as plt
import numpy as np
import os
data_path = os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'data/')).replace('\\', '/')
print(data_path)
print("---")
# reads x_u.txt file and fills x and u with values
def readFile(filename):
    x = []      # x-values
    y = []      # y-values
    with open(f'{data_path}/{filename}', 'r') as file:
        file.readline()
        for line in file:
            x_val, y_val = line.split(' ')
            x.append(float(x_val))
            y.append(float(y_val))
        
    x = np.array(x)     
    y = np.array(y)
    return x, y     

x, u = readFile('x_u.txt')
plt.plot(x, u)
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')
plt.title(r'Plot of exact solution of $u(x)$ for $x\in[0,1]$')
plt.savefig(f'{data_path}exactSolution.pdf')
plt.show()


# Plotting nummerical and exact solution for different values of n
plt.plot(x, u, label='exact solution')
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')

n_values = [10, 100, 1000]
for n in n_values:
    x, u = readFile(f'x_v_{n}.txt')
    plt.plot(x, u, label=f'n={n}', linestyle='--')
    plt.title(r"Plot of discrete solution $v(x)$ for differnt values of $n$")

plt.legend()
plt.savefig(f'{data_path}/exactVSdiscrete.pdf')
plt.show()