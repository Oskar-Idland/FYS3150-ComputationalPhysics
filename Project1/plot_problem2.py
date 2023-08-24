import matplotlib.pyplot as plt
import numpy as np

#read x_u.txt file
x_u = np.loadtxt('x_u.txt', delimiter=',')
x = x_u[:int(len(x_u)/2)]
u = x_u[int(len(x_u)/2):]

plt.plot(x, u)
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')
plt.title(r'Plot of exact solution of $u(x)$ for $x\in[0,1]$')
plt.savefig('plot_problem2.pdf')
plt.show()