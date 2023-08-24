import numpy as np
import matplotlib.pyplot as plt 
#import out

test = np.load("./out.npy")
test2 = np.load("./in.npy")
#print(test)
#print(test2)
#print(np.shape(test))



plt.plot(test2[0], test[0])
plt.show()