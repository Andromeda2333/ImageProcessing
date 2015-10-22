#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np
A=np.array([.2,.3,.6,.1,.9])
B=np.array([.1,.2,.7,.2,0])
print '欧几里得贴近度：',1-sum(abs(A-B)**2)**0.5/(5**0.5)
