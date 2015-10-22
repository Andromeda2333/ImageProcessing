#coding=utf-8
'''
Created on 2014年6月25日

@author: lenovo
'''

import numpy as np
persontype=np.dtype({'names':['name','age','weight'],
                     'formats':['S32','i','f']},align=True)
a=np.array([('zhang',32,75.5),('wang',24,65.2)]\
           ,dtype=persontype)
print a
print a.dtype
print a[1]
print a[1].dtype
print a[1]['name']

