#coding=utf-8
'''
Created on 2014年6月26日

@author: lenovo
'''
def f(x,y,z):
    t=abs(x-float(y))
    if t>z:
        return 0
    else:
        return 1-(t/z)**2

print f(167.8,163.4,4.8)
print f(4120,3866,800)