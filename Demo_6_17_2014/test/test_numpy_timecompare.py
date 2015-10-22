#coding=utf-8
'''
Created on 2014年6月25日

@author: lenovo
'''
import time
import math
import numpy as np
x=[i*0.001 for i in xrange(1000000)]
start=time.clock()
for i,t in enumerate(x):
    x[i]=math.sin(t)
print 'math.sin',time.clock()-start

y=np.array(x)
start=time.clock()
np.sin(y,y)
print 'numpy.sin:',time.clock()-start

start=time.clock()
for i,t in enumerate(x):
    x[i]=np.sin(t)
print 'numpy.sin loop:',time.clock()-start

