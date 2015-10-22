#coding=utf-8
'''
Created on 2014年7月3日

@author: lenovo
'''
import urllib2
req=urllib2.Request('http://www.baidu.com')
response=urllib2.urlopen(req)
print response.read()