#coding=utf-8
'''
Created on 2014年6月18日

@author: lenovo
'''
import sys
print 'My {1[spam]} runs {0.platform}'.format(sys,{'spam':'laptop'})
print 'My {conf[spam]} runs {s.platform}'.format(s=sys,conf={'spam':'laptop'})

somelist=list('spam')
print somelist
parts=somelist[0],somelist[-1],somelist[1:3]
print parts

testStr='a','sd','dsa'
print testStr

print 'first={0},last={1},middle={2}'.format(*parts)

temp='{0:10}={1:10}'.format('spam',123.456)
print temp

temp='{0:>10}={1:<10}'.format('spam',123.456)
print temp

temp='{0.platform:>10}={1[item]:<10}'.format(sys,{'item':123.456})
print temp















