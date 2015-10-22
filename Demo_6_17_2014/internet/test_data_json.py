#coding=utf-8
'''
Created on 2014年7月22日

@author: lenovo
'''
import json
obj=[[1,2,3],123,123.123,'abc',{'key1':(1,2,3),'key2':(4,5,6)}]
encodejson=json.dumps(obj,indent=4)
print repr(obj)
print encodejson

decodejson=json.loads(encodejson)
print type(decodejson)
print decodejson[4]['key1']
print decodejson
print decodejson