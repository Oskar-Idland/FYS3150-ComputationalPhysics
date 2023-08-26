import matplotlib.pyplot as plt
import numpy as np

x = []      # x-values
u = []      # u-values

# reads x_u.txt file and fills x and u with values
with open('x_u.txt', 'r') as file:
    file.readline()
    for line in file:
        x_val, u_val = line.split(' ')
        x.append(float(x_val))
        u.append(float(u_val))
    
x = np.array(x)     
u = np.array(u)     

plt.plot(x, u)
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')
plt.title(r'Plot of exact solution of $u(x)$ for $x\in[0,1]$')
plt.savefig('plot_problem2.pdf')
plt.show()