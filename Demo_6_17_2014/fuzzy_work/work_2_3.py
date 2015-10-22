#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np
def a(x):
    if x>=0 and x<=1:
        return x
    elif x>1 and x<=2:
        return 2-x
    else:
        return 0
    
def b(x):
    if x>=1 and x<=2:
        return x-1
    elif x>2 and x<=3:
        return 3-x
    else:
        return 0
    