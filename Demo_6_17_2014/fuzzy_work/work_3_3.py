#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np
R1=np.array([[.1,0,.8],[.0,.5,0],[0,.4,.3]])
R2=np.array([[.7,.2,.4],[.3,.1,.6],[1,.5,.2]])
print 'R1 or R2',np.maximum(R1,R2)
print 'R1 and R2 C',1-np.minimum(R1,R2)
print 'R1 C',1-R1