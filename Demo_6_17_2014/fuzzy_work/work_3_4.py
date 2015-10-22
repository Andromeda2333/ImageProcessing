#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np

def f(x,y):
    return max(np.minimum(x,y))
def g(A,B):
    a=A.shape[0]
    b=B.shape[1]
    C=np.zeros((a,b),np.double)
    for i in range(a):
        for j in range(b):
            C[i,j]=f(A[i,:],B[:,j])
    return C

R1=[[7,4,1,10],
    [8,3,6,3],
    [4,7,2,9]];
R1=np.array(R1)/10.0
R2=[[6,5],[2,8],[9,3],[8,10]]
R2=np.array(R2)/10.0
print g(R1,R2)
print g(R1,1-R2)