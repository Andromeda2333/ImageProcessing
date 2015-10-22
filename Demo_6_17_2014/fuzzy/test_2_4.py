#coding=utf-8
'''
Created on 2014年6月26日

@author: lenovo
'''
import numpy as np
A=np.array((0.6,0.8,  1,0.8,0.6,0.4))
B=np.array((0.4,0.6,0.8,  1,0.8,0.6))
print np.min(np.maximum(A,B))
print max(np.minimum(A,B))