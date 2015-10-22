#coding=utf-8
'''
Created on 2014年7月12日

@author: lenovo
'''
from test import test_class_1
from test.test_class_1 import Parent

class Son(test_class_1.Parent):
    '''
    classdocs
    '''


    def __init__(self, name,age,salary):
        '''
        Constructor
        '''
        Parent.__init__(self, name, age)
        self.salary=salary
    
    def talk(self,sth):
        Parent.talk(self, sth)
        
if (__name__=='__main__'):
    s=Son('李世石',56,5656)
    s.talk('你好评啊！！！！')
    s.show()
    