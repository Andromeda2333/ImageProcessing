#coding=utf-8
'''
Created on 2014年6月17日

@author: lenovo
'''


def Demo(D):
    for key in sorted(D):
        print key, '=>', D[key]
    
    for el in D:
        print el, D[el]


D={'a':1,'b':2,'c':3}

print D

print '***************'
Demo(D)
    
for c in 'saddsa':
    print c.upper()
    
x=0
while x<10:
    print 'hello!!'*x
    x+=1

squares=[x**2 for x in range(10)]
print squares

s=[]
for x in range(20):
    s.append(x**2)
print s
print 'f' in D

if not 'f' in D:
    print 'missing!!'
print D.get('x',99)

print D['x'] if 'x' in D else 0
D['a']=45
print D

T=(1,5,6,4,'a')
print T

