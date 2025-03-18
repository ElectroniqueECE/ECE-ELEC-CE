import numpy as np
import matplotlib.pyplot as plt
import math 

def fx_y(x,y):
    return 

def euler(h,x,y):
    return 

def rk2(h,x,y):
    return 


h=0.01
y0=0 

nb_points=

t=np.linspace(0,nb_points,nb_points)
x=np.linspace(0,h*nb_points,nb_points)

y_euler=np.linspace(0,0,nb_points)
y_rk2=np.linspace(0,0,nb_points)
solution=np.linspace(0,0,nb_points)

y_euler[0]=y0
y_rk2[0]=y0
solution[0]=y0

for i in range(nb_points):
    x[i]=


for i in range(1,nb_points):
    y_euler[i]=
    y_rk2[i]=
    solution[i]=
    
plt.plot(x,y_euler)


plt.show() 