#coding=utf-8
'''
Created on 2014年7月22日

@author: lenovo
'''
import json
data = {'b':789,'c':456,'a':123}
d1 = json.dumps(data,sort_keys=True,indent=4)
print d1

print 'DATA:', repr(data)
print 'repr(data)             :', len(repr(data))
print 'dumps(data)            :', len(json.dumps(data))
print 'dumps(data, indent=4)  :', len(json.dumps(data, indent=4))
print 'dumps(data, separators):', len(json.dumps(data, separators=(',',':')))

print json.dumps(data, separators=(',',':'))