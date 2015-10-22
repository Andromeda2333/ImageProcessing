#coding=utf-8
'''
Created on 2014年6月26日

@author: lenovo

利用格贴近度和择近原则解决茶叶鉴定
'''


import  numpy as np
from audioop import findmax
def f(A,B):
    A=np.array(A)
    B=np.array(B)
    a=max(np.minimum(A,B))
    b=min(np.maximum(A,B))
    return min(a,1-b)

a=(0.5, 0.4, 0.3, 0.6, 0.5, 0.4)
b=(0.3, 0.2, 0.2, 0.1, 0.2, 0.2)
c=(0.2, 0.2, 0.2,0.1,0.1, 0.2) 
d =(0.1, 0.1, 0.2, 0.1, 0.1, 0.1)
e=(0, 0.1, 0.1, 0.1,0.1, 0.1)
A=(0.4, 0.2, 0.1, 0.4, 0.5, 0.6)
x=[f(a,A),f(b,A),f(c,A),f(d,A),f(e,A)]
print x

