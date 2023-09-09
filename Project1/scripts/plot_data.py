import matplotlib.pyplot as plt
import numpy as np
import os
data_path = os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'data/')).replace('\\', '/')

def readFile(filename: str) -> tuple[np.ndarray]:
    ''' 
    reads .txt file and fills x and y with values\n
    filename [str]: inlcude .txt extension\n

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

x_exact, u = readFile('x_u.txt')
plt.plot(x_exact, u)
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')
plt.title(r'Plot of exact solution of $u(x)$ for $x\in[0,1]$')
plt.savefig(f'{data_path}/exactSolution.pdf')
plt.show()


''' 
plotting exact solution and numerical solution for different values of n 
'''
x_exact, u = readFile(f'x_u_{1000000}.txt')
plt.plot(x_exact, u, label='exact solution')
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x)$')

n_values = [10, 100, 1000, 10000, 100000, 1000000, 10000000]
for n in n_values:
    x, v = readFile(f'x_v_{n}.txt')
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
        x, v = readFile(f'x_v_{n}.txt')
        plt.plot(x, v, label=f'n={n}', linestyle='--')
        plt.title(r"Plot of discrete solution $v(x)$ for differnt values of $n$ together" + "\nwith exact solution " + r"$u(x)$")

plt.legend()
plt.savefig(f'{data_path}/exactVSdiscrete_wo10.pdf')
plt.show()


''' 
plotting the logarithm of the absolute error of the numerical solution for different values of n 
'''
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

''' 
plotting the logarithm of the relative error of the numerical solution for different values of n 
'''
for n in n_values:
    x, u = readFile(f'x_u_{n}.txt')
    x, v = readFile(f'x_v_{n}.txt')
    ''' removing end points'''
    x = x[1:-1]
    u = u[1:-1]
    v = v[1:-1]
    ϵ = np.abs((u - v)/u)
    print(np.max(ϵ))
    print(x[np.argmax(ϵ)])
    rel_err = np.log10(ϵ)

    plt.plot(x, rel_err, label=f'n={n}')

plt.title(r"Plot of the logarithm of the relative error $|(u_i - v_i)/u_i|$ of the discrete" + "\n" + r"solution $v(x)$ for differnt values of $n$")
plt.legend()
plt.savefig(f'{data_path}/relative_error.pdf')
plt.show()


runtime_general = [[5e-07, 3.33e-07, 4.58e-07, 4.58e-07, 5e-07],
                   [2.625e-06, 2.292e-06, 2.333e-06, 2.708e-06, 2.625e-06],
                   [2.6708e-05, 2.3417e-05, 2.3167e-05, 2.6792e-05, 2.6583e-05],
                   [0.000264875, 0.000229875, 0.000226917, 0.000300041, 0.000265166],
                   [0.00263437, 0.0022945, 0.00229908, 0.00263437, 0.00261896],
                   [0.0292246, 0.0241653, 0.0270453, 0.0292246, 0.0286908]]

runtime_special = [[2.91e-07, 4.16e-07, 4.17e-07, 3.33e-07, 4.59e-07],
                   [1.958e-06, 2.292e-06, 2.75e-06, 3.125e-06, 2.667e-06],
                   [2.0542e-05, 2.3125e-05, 2.7625e-05, 2.5834e-05, 2.5959e-05],
                   [0.000200916, 0.000223125, 0.00029775, 0.000297125, 0.0002545],
                   [0.00201287, 0.0022645, 0.00296925, 0.00256213, 0.00254967],
                   [0.0208238, 0.0229941, 0.0271131, 0.0302535, 0.0265217]]

idx = np.arange(6)
labels = ['1st', '2nd', '3rd', '4th', '5th', 'Mean']
steps = [10, 100, 1000, r'$10^4$', r'$10^5$', r'$10^6$']
for i in range(6):
    general = runtime_general[i]
    general.append(np.mean(runtime_general[i]))
    special = runtime_special[i]
    special.append(np.mean(runtime_special[i]))

    plt.bar(idx - 0.33, general, color = '#ffaed7', width = 0.33, label = 'General')
    plt.bar(idx, special, color = 'skyblue', width = 0.33, label = 'Special')
    plt.legend()
    plt.xticks(idx - 0.33/2, labels = labels)
    plt.xlabel('Run')
    plt.ylabel('Duration [s]')
    plt.title(f'Duration of 5 runs with {steps[i]} steps using the general algorithm\nversus the special algorithm, along with the mean')
    plt.tight_layout()
    plt.savefig(f'{data_path}/runtime_comparison_{10**(i+1)}.pdf')
    plt.show()