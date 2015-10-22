#coding=utf-8
'''
Created on 2014年6月26日

@author: lenovo
'''
import numpy as np
A=np.array((0.3,0.1,0.7,0.5,1   ))
B=np.array((0.3,   0,0.8,0.4,0.9))
AOB=max(np.minimum(A,B))
AUB=min(np.maximum(A,B))
N1=min(AOB,1-AUB)
print AOB,AUB,N1