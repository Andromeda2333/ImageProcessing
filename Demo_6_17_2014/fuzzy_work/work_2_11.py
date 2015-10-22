#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np
def f(a,b,c):
    x=range(5)
    x[0]=1-max(a-b,b-c)/60.0
    x[1]=1-abs(a-90)/90.0
    x[2]=1-(a-c)/180.0
    x[3]=min(x[0],x[1])
    x[4]=1-max(x[0:3])
    return x
    
print f(89,46,45)