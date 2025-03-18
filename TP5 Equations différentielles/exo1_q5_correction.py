import numpy as np
import matplotlib.pyplot as plt
import math 

n=8
ck=[0, 0, 0, 0, 0, 0,0,0,1]
uk=np.linspace(0,0,n+3)
uk[n+1]=0
uk[n+2]=0

h=0.02
nb_points=200

x=np.linspace(0,0,nb_points)
y=np.linspace(0,0,nb_points)

for i in range(0,nb_points):
    x[i]=-2+i*h
    for k in range(n,-1,-1):
        uk[k]=ck[k]+2*x[i]*uk[k+1]-2*(k+1)*uk[k+2]
    y[i]=uk[0]
        
plt.plot(x, y)
plt.grid()
plt.show() 