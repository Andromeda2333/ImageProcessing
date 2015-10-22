#coding=utf-8
'''
Created on 2014年6月26日

@author: lenovo
'''
import numpy as np
import time
start=time.clock()
R=np.array([[1,.2,.7],[0.8,.1,.3]])
S=np.array([[.6,.9,.8],[.4,.5,.1]])
print np.maximum(R,S)
print np.minimum(R,S)
print 1-R
print time.clock()-start
print type(R.shape)
print np.ones(R.shape, np.int)
print R.shape[:]