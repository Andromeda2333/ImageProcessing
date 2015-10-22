#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np


def f(A,R):
    B=[0,0,0,0]
    for i in range(4):
        B[i]=max(np.minimum(A,R[:,i]))
    return B

R=[[1,0,1,0],
   [0,1,0,0],
   [0,0,1,1]]
R=np.array(R)
A=np.array([1,0,1])
B=np.array([.5,.3,0])
print f(A,R)
print f(B,R)
