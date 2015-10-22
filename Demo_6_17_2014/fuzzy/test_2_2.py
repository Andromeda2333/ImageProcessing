#coding=utf-8
'''
Created on 2014年6月26日

@author: lenovo
'''
import numpy as np
A=(0.5,0.3,0.8,0.2,0.4)
B=(0.6,0.8,0.9,0.5,0.2)
A=np.array(A)
B=np.array(B)
print 1-sum(abs(A-B))/5
print 1-(sum(abs(A-B)**2)/5)**(1/2.0)