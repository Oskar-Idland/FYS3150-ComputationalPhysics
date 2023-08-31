import matplotlib.pyplot as plt
import numpy as np
import os
data_path = os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'data/')).replace('\\', '/')

def readFile(filename):
    ''' reads .txt file and fills x and y with values '''
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


''' plotting exact solution and numerical solution for different values of n '''
plt.plot(x, u, label='exact solution')
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')

n_values = [10, 100, 1000, 10000]
for n in n_values:
    x, v = readFile(f'x_v_{n}.txt')
    plt.plot(x, v, label=f'n={n}', linestyle='--')
    plt.title(r"Plot of discrete solution $v(x)$ for differnt values of $n$ together" + "\nwith exact solution " + r"$u(x)$")

plt.legend()
plt.savefig(f'{data_path}/exactVSdiscrete.pdf')
plt.show()


''' plotting the logarithm of the absolute error of the numerical solution for different values of n '''
for n in n_values:
    x, u = readFile(f'x_u_{n}.txt')
    x, v = readFile(f'x_v_{n}.txt')
    ''' removing end points'''
    x = x[1:-1]
    u = u[1:-1]
    v = v[1:-1]
    abs_err = np.log10(np.abs(u - v))

    plt.plot(x, abs_err, label=f'n={n}')
    plt.title(r"Plot of the logarithm of the absolute error $|(u_i - v_i)|$ of the discrete" + "\n" + r"solution $v(x)$ for differnt values of $n$")

plt.legend()
plt.savefig(f'{data_path}/absolute_error.pdf')
plt.show()

''' plotting the logarithm of the relative error of the numerical solution for different values of n '''
for n in n_values:
    x, u = readFile(f'x_u_{n}.txt')
    x, v = readFile(f'x_v_{n}.txt')
    ''' removing end points'''
    x = x[1:-1]
    u = u[1:-1]
    v = v[1:-1]
    rel_err = np.log10(np.abs((u - v)/u))

    plt.plot(x, rel_err, label=f'n={n}')
    plt.title(r"Plot of the logarithm of the relative error $|(u_i - v_i)/u_i|$ of the discrete" + "\n" + r"solution $v(x)$ for differnt values of $n$")

plt.legend()
plt.savefig(f'{data_path}/relative_error.pdf')
plt.show()