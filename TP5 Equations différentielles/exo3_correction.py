import numpy as np
import matplotlib.pyplot as plt
import math 

def fx_y(x,y):
    return math.exp(-x)-math.exp(-4*x)*y



def rk4(h,x,y):
    k1=fx_y(x,y)
    k2=fx_y(x+h/2,y+h*k1/2)
    k3=fx_y(x+h/2,y+h*k2/2)
    k4=fx_y(x+h,y+h*k3)
    return h*(k1+2*k2+2*k3+k4)/6

h=0.01
y0=0 

nb_points=500

t=np.linspace(0,nb_points,nb_points)
x=np.linspace(0,h*nb_points,nb_points)

y_rk4=np.linspace(0,0,nb_points)

y_rk4[0]=y0

for i in range(nb_points):
    x[i]=h*i


for i in range(1,nb_points):
    y_rk4[i]=y_rk4[i-1]+rk4(h,x[i-1],y_rk4[i-1])

    
plt.plot(x,y_rk4)
plt.grid()

plt.show() 