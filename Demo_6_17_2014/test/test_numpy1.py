#coding=utf-8
'''
Created on 2014年6月24日

@author: lenovo
'''
import numpy as np
import numpy
a=np.array([1,2,3,4])
print a
b=numpy.array((5,6,7,8))
print  b
c=np.array([[1,2,3],
            [4,5,6],
            [7,8,9]])
print c
print a.shape
print c.shape
c.shape=9,1
print c
print c.dtype
