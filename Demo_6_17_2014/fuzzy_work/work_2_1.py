#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np
A=np.array([.6,.8,1,.8,.6,.2])
B=np.array([.4,.6,.5,1,.8,.3])
print '海明贴近度：',1-sum(abs(A-B))/6
print '欧几里得贴近度：',1-sum(abs(A-B)**2)**0.5/(6**0.5)
print '格贴近度：',min(max(np.minimum(A,B)),1-min(np.maximum(A,B)))
