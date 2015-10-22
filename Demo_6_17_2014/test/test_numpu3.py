#coding=utf-8
'''
Created on 2014年6月25日

@author: lenovo
'''
import numpy as np
x=np.arange(10,1,-1)
print x[np.array([3,3,1,8])]

print x[np.array([[3,3,1,8],[3,3,-3,8]])]
x=np.random.rand(5)
print np.array(x>0.3)
x=np.arange(36)
x.shape=6,6
print x
print '*'*20
print x[0,3:5]
print x[4:,4:]
print x[:,2]
print x[2::2,::2]
print '*'*56
x=np.arange(0,60,10).reshape(-1,1)+np.arange(0,6)
print x
idx=slice(None,None,2),slice(2,None)
print idx
print  x[idx]
print np.s_[:2,:]

class S(object):
    def __getitem__(self,index):
        return index
print S()[::2,2:]

print '*'*45
x=np.arange(10)
y=x[2:5]
print y
y[:]=1,2,3
print y
print 'x=',x

