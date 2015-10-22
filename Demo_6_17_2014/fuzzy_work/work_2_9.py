#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np

def f(X,Y):
    a=max(np.minimum(X,Y))
    b=min(np.maximum(X,Y))
    return min(a,1-b)
    


A1=np.array([2,4,5,1])/10.0
A2=np.array([2,5,3,1])/10.0
A3=np.array([2,3,4,1])/10.0
B1=np.array([0,6,3,1])/10.0
B2=np.array([2,3,5,0])/10.0

print 'B1,A1:',f(B1,A1)
print 'B1,A2:',f(B1,A2)
print 'B1,A3:',f(B1,A3)
print '*'*100
print 'B2,A1:',f(B2,A1)
print 'B2,A2:',f(B2,A2)
print 'B2,A3:',f(B2,A3)