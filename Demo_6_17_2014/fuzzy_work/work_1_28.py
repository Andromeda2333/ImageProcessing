#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np
def f(A):
    B=np.zeros(A.shape,np.int)
    for i in range(A.shape[0]):
        if A[i]>=0.5:
            B[i]=1
        else:
            B[i]=0
    return B 
       
A=np.array([.8,.9,.1,.8])
B=np.array([0.3,0,0.3,0])
A1=f(A)
B1=f(B)
print (sum((abs(A-A1))**2)**0.5)*2/2
print sum(abs(B-B1)**2)**0.5*2/2


def s(X):
    if X>0 and X<1:
        return -X*np.log(X)-(1-X)*np.log(1-X)
    else:
        return 0

C=np.array([1,3,7,8,5])/10.0
D=[s(x) for x in C]
print D
print sum(D)/(5*np.log(2))

