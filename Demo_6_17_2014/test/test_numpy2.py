#coding=utf-8
'''
Created on 2014年6月24日

@author: lenovo
'''
import numpy as np
a=np.array([1,2,3,4],np.float64)
print a 
b=np.array([1,2,3,4],np.complex)
print b

print np.typeDict['d']
print np.typeDict['double']
print np.typeDict['float64']
print set(np.typeDict.values())
print np.arange(0,1,0.1)
print np.linspace(0, 1, 10, endpoint=False)
print np.linspace(0, 1, 10, endpoint=True)
print np.logspace(0, 2, 10,base=10)
print type(a)
print np.ones(shape=(3,8), dtype='d')
print np.empty((5,6),np.double)
s='adasferrare'
print np.fromstring(s,np.int8)

def func(i):
    return i%4+1

print np.fromfunction(func, (5,))

def func2(i,j):
    return (i+1)*(j+1)
print np.fromfunction(func2, (9,9))

arr1=np.array([1,23,6,5,6,68,6,6,5])
print arr1[[1,3,5]]


