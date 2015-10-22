#coding=utf-8
'''
Created on 2014年7月19日

@author: lenovo
'''
import numpy as np
persontype=np.dtype({
                     'names':['name','age','weight'],
                     'formats':['S32','i','f']},align=True)
a=np.array([('zhang',32,75.5),('wang',24,65.2)],dtype=persontype)
# print a.dtype
print a[0].dtype
print a[0]['name']
a.tofile('test.bin')