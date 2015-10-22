#coding=utf-8
'''
Created on 2014年7月2日

@author: lenovo
'''
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
fig=plt.figure(1)
fig.patch.set_color('g')
fig.canvas.draw()
fig2=plt.figure(2)
ax1=plt.subplot(211)
ax2=plt.subplot(212)

x=np.linspace(0,3,100)
for i in xrange(5):
    plt.figure(1)
    plt.plot(x,np.exp(i*x/3))
    plt.sca(ax1)
    plt.plot(x,np.sin(i*x))
    plt.sca(ax2)
    plt.plot(x,np.cos(i*x))
plt.show()
print fig2.axes
print type(fig2)
print matplotlib.get_configdir()

