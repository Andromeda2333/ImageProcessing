#coding=utf-8
'''
Created on 2014年6月25日

@author: lenovo
'''
import numpy as np
x=np.arange(36).reshape(6,6)
y=x[[0,1,2,3],[1,2,3,4]]
y[:]=[0,0,0,0]
print x
z=x[0:4,1:5]
z[:]=[0,0,0,0]
print x