#coding=utf-8
'''
Created on 2014年7月3日

@author: lenovo
'''
import urllib2
response=urllib2.urlopen('http://www.baidu.com/')
html=response.read()
print html