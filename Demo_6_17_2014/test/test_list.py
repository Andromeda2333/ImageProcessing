#coding=utf-8
'''
Created on 2014年6月19日

@author: lenovo
'''
L=[1,23,23,2,3,2,4,34,3]
print  L
L.extend([12,43,43,5,34])
print L
L.append([2,4,4])
print L
L.remove(2)
print L
del L[-1]
print L
L=[231]+L
print L