import numpy as np
import matplotlib.pyplot as plt
import math 

def fx_y(x,y):
    return -8*y+math.exp(-4*x)

def euler(h,x,y):
    return y+h*fx_y(x, y)

def rk2(h,x,y):
    return y+(4*h/5)*fx_y(x,y)+(h/5)*fx_y(x+5*h/2,y+5*h*fx_y(x,y)/2)


h=0.01
y0=0 

nb_points=200

t=np.linspace(0,nb_points,nb_points)
x=np.linspace(0,h*nb_points,nb_points)

y_euler=np.linspace(0,0,nb_points)
y_rk2=np.linspace(0,0,nb_points)
solution=np.linspace(0,0,nb_points)

y_euler[0]=y0
y_rk2[0]=y0
solution[0]=y0

for i in range(nb_points):
    x[i]=i*h


for i in range(1,nb_points):
    y_euler[i]=euler(h,x[i-1],y_euler[i-1])
    y_rk2[i]=rk2(h,x[i-1],y_rk2[i-1])
    solution[i]=(math.exp(-4*x[i])-math.exp(-8*x[i]))/4
    
plt.plot(x,y_euler)
plt.plot(x,y_rk2)
plt.plot(x,solution)
plt.show() 