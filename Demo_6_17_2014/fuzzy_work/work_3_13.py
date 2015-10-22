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

F=[[3,6,1,0],[0,2,5,3],
   [5,3,1,1],[1,3,2,4]]
F=np.array(F)/10.0
A=np.array([.5,.2,.2,.1])
B=np.array([.2,.4,.1,.3])
print f(A,F)
print f(B,F)

B=np.array([1,2,4,3])/10.0
A1=np.array([3,5,1,1])/10.0
A4=np.array([.2,.4,.1,.3])
A3=np.array([.2,.3,.2,.3])
print f(A1,F)
print max(np.minimum(f(A1,F),B))
print max(np.minimum(f(A4,F),B))
print max(np.minimum(f(A3,F),B))
