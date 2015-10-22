#coding=utf-8
'''
Created on 2014年6月18日

@author: lenovo
'''

class Woker(object):
    '''
    classdocs
    '''


    def __init__(self, name,pay):
        '''
        Constructor
        '''
        self.name=name
        self.pay=pay
    
    def lastName(self):
        return self.name.split()[-1]
    def giveRaise(self,percent):
        self.pay*=1+percent
        