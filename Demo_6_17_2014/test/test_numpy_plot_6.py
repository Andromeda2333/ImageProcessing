#coding=utf-8
'''
Created on 2014年7月3日

@author: lenovo
'''
import numpy as np
import matplotlib.pyplot as plt
def triangle_wave(x,c,c0,hc):
    x=x-int(x)
    if x>=c:r=0.0
    elif x<c0:r=x/c0*hc
    else:r=(c-x)/(c-c0)*hc
    return r
x=np.linspace(0,10,1000)
y1=np.array([triangle_wave(t, 0.6, .4, 1.0) for t in x])
plt.plot(x,y1,'r-')
plt.xlim([-0.2,10.3])
plt.ylim([-0.2,1.3])
plt.grid(True)
plt.show()