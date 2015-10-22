#coding=utf-8
'''
Created on 2014年7月22日

@author: lenovo
'''
class Person(object):
    def __init__(self,name,age):
        self.name = name
        self.age = age
    def __repr__(self):
        return 'Person Object name : %s , age : %d' % (self.name,self.age)
if __name__  == '__main__':
    p = Person('Peter',22)
    print p