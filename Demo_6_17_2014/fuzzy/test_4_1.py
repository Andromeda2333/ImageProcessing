#coding=utf-8
'''
Created on 2014年6月27日

@author: lenovo
'''
import numpy as np
def f(x,y):
    size=y.shape[1]
    return [max(np.minimum(x,y[:,i])) for i in range(size)]

R=[[.5,.2,0,1],
   [1,.3,0,.1],
   [.6,.8,.4,.2],
   [.3,1,0,0],
   [0,0,0,0]
   ]
R=np.array(R)
A=np.array([1,1,0,0,0])
print f(A,R)

B=np.array([.5,.6,.9,1,0])
print f(B,R)



