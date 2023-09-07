import matplotlib.pyplot as plt
import numpy as np
import os
data_path = os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'data/')).replace('\\', '/')

def readFile(filename: str) -> tuple[np.ndarray, np.ndarray]:
    ''' 
    reads .txt file and fills x and y with values\n
    filename [str]: DO NOT inlcude .txt extension\n

    # Returns
    A tuple of two arrays, x and y 
    '''
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

def readBinFile(filename: str) -> tuple[np.ndarray, np.ndarray]:
    ''' 
    # Input
    reads .bin file and fills x and y with values\n
    filename [str]: DO NOT include .bin extension\n

    # Returns
    A tuple of two arrays, x and y 
    '''
    data = np.fromfile(f'{data_path}/{filename}')
    data = data.reshape((-1, 2))
    x = data[:, 0]
    y = data[:, 1]
    return x, y

x_exact, u = readBinFile('x_u')
print(u[1])
print(np.finfo(np.longdouble).eps)
plt.plot(x_exact, u)
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')
plt.title(r'Plot of exact solution of $u(x)$ for $x\in[0,1]$')
plt.savefig(f'{data_path}exactSolution.pdf')
plt.show()


''' 
plotting exact solution and numerical solution for different values of n 
'''
x_exact, u = readBinFile(f'x_u_{1000000}')
plt.plot(x_exact, u, label='exact solution')
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')

n_values = [10, 100, 1000, 10_000]
for n in n_values:
    x, v = readBinFile(f'x_v_{n}')
    plt.plot(x, v, label=f'n={n}', linestyle='--')
    plt.title(r"Plot of discrete solution $v(x)$ for differnt values of $n$ together" + "\nwith exact solution " + r"$u(x)$")

plt.legend()
plt.savefig(f'{data_path}/exactVSdiscrete.pdf')
plt.show()


''' 
plotting exact solution and numerical solution for different values of n, but now without n = 10
'''
plt.plot(x_exact, u, label='exact solution')
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')

for n in n_values:
    if n != 10:
        x, v = readBinFile(f'x_v_{n}')
        plt.plot(x, v, label=f'n={n}', linestyle='--')
        plt.title(r"Plot of discrete solution $v(x)$ for differnt values of $n$ together" + "\nwith exact solution " + r"$u(x)$")

plt.legend()
plt.savefig(f'{data_path}/exactVSdiscrete_wo10.pdf')
plt.show()


''' 
plotting the logarithm of the absolute error of the numerical solution for different values of n 
'''
for n in n_values:
    x, u = readBinFile(f'x_u_{n}.txt')
    x, v = readBinFile(f'x_v_{n}.txt')
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

''' 
plotting the logarithm of the relative error of the numerical solution for different values of n 
'''
for n in n_values:
    x, u = readBinFile(f'x_u_{n}.txt')
    x, v = readBinFile(f'x_v_{n}.txt')
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