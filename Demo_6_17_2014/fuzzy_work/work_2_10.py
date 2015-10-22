#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np
def g(x,a,b):
    return np.exp(-((x-a)/b)**2)
def f(x):
    Y=np.zeros((1,5),np.double)
    Y[0,0]=g(x, 3.7, 0.3)
    Y[0,1]=g(x,2.9,0.3)
    Y[0,2]=g(x,5.6,0.3)
    Y[0,3]=g(x,3.9,0.3)
    Y[0,4]=g(x,3.7,0.2)
    return Y
print f(4.6)
