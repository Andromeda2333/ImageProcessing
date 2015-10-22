#coding=utf-8
'''
Created on 2014年7月2日

@author: lenovo
'''
import numpy as np
import matplotlib.pyplot as plt
from cProfile import label
x=np.linspace(0, stop=10, num=100)
y=np.sinc(x)
z=np.cos(x**2)
plt.figure(figsize=(8,4))
plt.plot(x,y,label='$sin(x)$',color='r',linewidth=2)
plt.plot(x,z,'g--',label='$cos(x^2)$')
plt.xlabel('Time(s)')
plt.ylabel('Volt')
plt.title('Pyplot First Example')
plt.ylim(-1.2,1.2)
plt.legend()
# plt.savefig('mytest.png',dpi=120)
plt.show()