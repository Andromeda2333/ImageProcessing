#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np
def R1(x,y):
    return np.exp(-(x-y)**2.0)
def R2(x,y):
    return np.exp(-(x-y))
print 1-max(R1(3.0,2.0),R2(3.0,2.0))
print min(1-R1(3.0,2.0),1-R2(3.0,2.0))