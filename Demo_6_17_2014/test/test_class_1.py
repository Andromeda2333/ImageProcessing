#coding=utf-8
'''
Created on 2014年7月12日

@author: lenovo
'''

class Parent(object):
    '''
    classdocs
    '''


    def __init__(self, name,age):
        '''
        Constructor
        '''
        self.name=name
        self.age=age
    def show(self):
        print 'name:',self.name
        print 'age:',self.age
    def talk(self,sth):
        print '在说 %s'%sth
        