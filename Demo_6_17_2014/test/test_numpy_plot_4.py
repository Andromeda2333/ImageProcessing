#coding=utf-8
'''
Created on 2014年7月2日

@author: lenovo
'''
import matplotlib.pyplot as plt
import numpy as np
x=np.arange(0,5,.1)
line=plt.plot(x,x*x)[0]
line.set_alpha(0.5)
lines=plt.plot(x,np.sin(x),x,np.cos(x))
plt.setp(lines,color='r',linewidth=2)
plt.ylim(-1.3,1.3)
plt.grid(True)
plt.show()
print plt.getp(lines[0])
