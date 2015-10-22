#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
def f(x):
    return 1-(x-1)/9.0
def g(x):
    return (x-1)/9.0

src=[x for x in range(1,11,1)]
A={x:f(x) for x in src}
B={x:g(x) for x in src}
print 'A=',A
print 'B=',B