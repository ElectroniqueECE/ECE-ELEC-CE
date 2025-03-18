import numpy as np
import matplotlib.pyplot as plt
import math 

def fx_y(x,y):
    return -y+math.exp(-x)



def rk2(h,x,y):
    return y+h*fx_y(x+h/2,y+h*fx_y(x,y)/2)


h=0.1
y0=float(input('y0 initial : ')) # c est 0 la valeur initiale

nb_points=400

t=np.linspace(0,nb_points,nb_points)
x=np.linspace(0,h*nb_points,nb_points)

y=np.linspace(0,0,nb_points)
solution=np.linspace(0,0,nb_points)

y[0]=y0


for i in range(1,nb_points):
    y[i]=rk2(h,x[i-1],y[i-1])
    solution[i]=x[i]*math.exp(-x[i])
    
plt.plot(t, y,solution)
plt.show() 