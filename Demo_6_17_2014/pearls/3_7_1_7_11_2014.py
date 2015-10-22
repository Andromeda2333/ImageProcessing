#coding=utf-8
'''
Created on 2014年7月11日

@author: lenovo
'''
import math
def f(x):
    if x<=2200:
        return 0
    if x>102200:
        return 53090+.70*(x-102200)
    
    y=0
    n=(x-2200)/500
    rest=x-2200-n*500
    w=0.14
    
    for i in range(n):
        y=y+w*500
        w=w+0.01
    return y+rest*w

print f(2100)
print f(2700)
print f(5000)
print f(3700)

