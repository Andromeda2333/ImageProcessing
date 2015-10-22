#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
'''
比5大得多的实数
'''

import math
def f(x):
    if x<=5:
        return 0
    else:
        return 1.0/(1.0+100000/((x-5.0)**2))
for x in range(-100,10000,1):
    print x,f(x)