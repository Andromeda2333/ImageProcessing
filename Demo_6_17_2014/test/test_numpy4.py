#coding=utf-8
'''
Created on 2014年6月25日

@author: lenovo
'''
import math
import numpy as np
print type(math.sin(0.5))
print type(np.sin(0.5))
a=np.arange(6).reshape(2,3)
print type(a[1,1])
print type(a.item(1,1))

x=np.array([1,3,5,6])
y=np.array([4,8,9,6])
print x+y
print np.add(x,y)
print np.add(x,y,x)
print x


