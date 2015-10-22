#coding=utf-8
'''
Created on 2014年6月19日

@author: lenovo
'''
a=[1,23,43,4,5,45,346]
print a
print sorted(a)
print a
print '*'*20
a.sort(cmp=None, key=None, reverse=False)
print a

b=['eqw','324']
print a+b
print 'sum=',sum(a)
a.append(b)
print a 

L=list('dadads')
print L

print [x*4 for x in L]

arry=[x for x in range(0,100,2)]
print arry
print [x**3 for x in arry]


print [0 for x in range(10)]*10



