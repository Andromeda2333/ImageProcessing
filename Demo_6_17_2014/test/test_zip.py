#coding=utf-8
'''
Created on 2014年6月28日

@author: lenovo
'''
a=['a','b','c']
b=[1,2,3]
print dict(zip(a,b))

print dict.fromkeys('spam',0)
print list('spam')

d=dict(a=1,b=2,c=3)
print d
k=d.keys()
print d.items()
k.sort()
print k
