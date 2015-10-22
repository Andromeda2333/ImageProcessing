#coding=utf-8
'''
Created on 2014年6月27日

@author: lenovo
'''
import numpy as np

def f(x,y):
    return max(np.minimum(x,y))
def g(A,B):#求解闭包
    size=A.shape[0]
    ANS=np.zeros(A.shape,np.float)
    for i in range(size):
        for j in range(size):
            ANS[i,j]=f(A[i,:],B[:,j])
    return ANS
R=np.array([[1,.3,.4],[.3,1,.6],[.4,.6,1]])
R2=g(R,R)
R4=g(R2,R2)
R8=g(R4,R4)
print 'R=',R
print 'R2=',R2
print 'R4=',R4
print 'R8=',R8
print 'R3=',g(R,R2)
