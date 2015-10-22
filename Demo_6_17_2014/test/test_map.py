#coding=utf-8
'''
Created on 2014年6月17日

@author: lenovo
'''
d={'food':'spam','quantity':4
   ,'color':'pink'}
for i in d:
    print i
print '*******************'    
print d    
print d.keys()

Keys=d.keys()
print '*******************'
print Keys
Keys.sort()
print '*******************'
print Keys

for key in Keys:
    print key,'=>',d[key]