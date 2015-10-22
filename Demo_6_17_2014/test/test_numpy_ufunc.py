#coding=utf-8
'''
Created on 2014年6月25日

@author: lenovo
'''
import numpy as np
x=np.linspace(0, 2*np.pi, 10)
y=np.sin(x)
print x
print y
print id(x),id(y)
z=np.sin(x,x)
print id(x),id(z)
print x
