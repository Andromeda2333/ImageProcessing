#coding=utf-8
'''
Created on 2014年6月26日

@author: lenovo
计算两个元素的相关度
'''
import math
def f(u,v):
    return math.exp(-(u-v)**2)
print f((math.log(2))**(0.5),0)
print f((math.log(3))**(0.5)+1,1)