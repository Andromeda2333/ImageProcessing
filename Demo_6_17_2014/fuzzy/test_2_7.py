#coding=utf-8
'''
Created on 2014年6月26日

@author: lenovo
'''
import  numpy as np
def f(A,B):
    A=np.array(A)
    B=np.array(B)
    a=max(np.minimum(A,B))
    b=min(np.maximum(A,B))
    return min(a,1-b)
A1=(1, 0.8, 0.5, 0.4, 0, 0.1)
A2=(0.5, 0.1, 0.8, 1, 0.6, 0)
A3=(0, 1, 0.2, 0.7, 0.5, 0.8)
A4=(0.4, 0, 1, 0.9, 0.6, 0.5)
A5=(0.8, 0.2, 0, 0.5, 1, 0.7)
A6=(0.5, 0.7, 0.8, 0, 0.5, 1)
B=(0.7, 0.2, 0.1, 0.4, 1, 0.8 )

x=[f(A1,B),f(A2,B),f(A3,B),f(A4,B),f(A5,B),f(A6,B)]
print x

