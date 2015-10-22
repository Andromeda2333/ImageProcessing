#coding=utf-8
'''
Created on 2014年6月17日

@author: lenovo
'''
X=set('spam')
Y={'h','a','m'}
print 'X=',X
print 'X,Y=',X,Y
print 'X&Y=',X&Y
print 'X|Y=',X|Y
print 'X-Y=',X-Y

print {x**2 for x in [1,3,5,8]}

L=[1,2,3,2,31,12,31,2,21,3,1,1,1,1]
print L
S=set(L)

L=list(S)
print L
print S

