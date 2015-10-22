#coding=utf-8
'''
Created on 2014年6月18日

@author: lenovo
'''
S='spammy'
L=list(S)
print 'S=',S,'L=',L
print ''.join(L)

print '*'*56
line='aaa bbb ccc'
print line[0:3]
print line[8:]

print line.split()

line='this is a statment\n'
print line
print line.rstrip()
print line.upper()
print line.endswith('t\n')
print line.startswith('this')

print line.replace('is', '&&')
print line

print '%(n)d,%(x)s'%{'n':45,'x':4554}

food='spam'
age=40

print vars()

template='{0},{1} and {2}'
result=template.format('spam','ham','eggs')
print result
print type(result)






