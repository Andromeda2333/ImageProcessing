#coding=utf-8
'''
Created on 2014年6月27日

@author: lenovo
'''
import numpy as np

A=np.array([1,2,3,4])
B=np.array([4,5,6,7])
print np.dot(A,B)
print np.multiply(A,B)
print A*B

x=np.array([.2,.3,.3,.2])
y=np.array([.1,.03,0,.4])
z=np.array([.3,.135,.786,1])

print x.dot(z)
print x.dot(y)

C=[1.86,2.06,2,1.95,1.61]
C=np.array(C)
print C/sum(C)
