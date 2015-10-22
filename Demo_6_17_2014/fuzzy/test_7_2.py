#coding=utf-8
'''
Created on 2014年6月28日

@author: lenovo
'''
import numpy as np
def f(A,B):
    n=A.shape[0]
    m=B.shape[0]
    ANS=np.ones(shape=(n,m), dtype=np.double)
    for i in range(n):
        for j in range(m):
            ANS[i,j]=min(A[i],B[j])
    return ANS

def g(A,B):
    (n,m)=A.shape
    ANS=np.zeros((n,m),np.double)
    for i in range(n):
        for j in range(m):
            ANS[i,j]=max(A[i,j],B[i,j])
    return ANS
A=np.array([1,.4,0])
B=np.array([0,.4,1])
C=np.array([1,.6,0])
AB=f(A,B)
AC=f(1-A,C)
print g(AB,AC)