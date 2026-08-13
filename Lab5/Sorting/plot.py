import numpy as np
import matplotlib.pyplot as plt

x = [10,100,1000,10000,100000,200000]
bubble=[1.2e-06,.0000854,.0021046,.219396,28.0298,111.86]
selection = [1.2e-06,1.6e-05,0.0007039,0.057176,5.42693,20.8005]
insertion=[7e-07,1.04e-05,0.0009089,0.0900213,8.28157,32.6454]
heap=[1.6e-06,1.86e-05,0.0002522,0.0034024,0.0517279,0.0958038]
merge=[2.57e-05,8.11e-05,0.0004816,0.004967,0.048125,0.11123]
shell_sort=[1e-06,1.47e-05,0.0003021,0.0037627,0.0457159,0.102896]

plt.plot(x,bubble,label="Bubble Sort")
plt.plot(x,selection,label="Selection Sort")
plt.plot(x,insertion,label="Insertion Sort")
plt.plot(x,heap,label="Heap Sort")
plt.plot(x,merge,label="mergeSort")
plt.plot(x,shell_sort,label="Shell Sort")
plt.xlabel("Array Size")
plt.ylabel("Time Taken(s)")
plt.title("Bubble Sort Time Complexity Graph")
plt.legend()
plt.savefig('plot.png')
plt.show()


