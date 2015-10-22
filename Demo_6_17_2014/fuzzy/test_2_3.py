#coding=utf-8
'''
Created on 2014年6月26日

@author: lenovo
'''
def A(x):
    x=float(x)
    if 0<=x<20:
        return 0
    if 20<=x<60:
        return (x-20)/40
    if 60<=x<=100:
        return 1
def B(x):
    x=float(x)
    if 80<=x<=100:
        return 0
    if 40<=x<80:
        return (80-x)/40
    if 0<=x<=40:
        return 1

x=40
print max(A(x),B(x))