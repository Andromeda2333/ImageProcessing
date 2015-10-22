#coding=utf-8
'''
Created on 2014年7月23日

@author: lenovo
'''
import json;    
import urllib2  
  
page=urllib2.urlopen("http://m.weather.com.cn/data/101010100.html").read()  
jsonVal = json.loads(page,encoding='utf-8')
out_js=json.dumps(jsonVal,ensure_ascii=False,indent=4)   
js=json.loads(out_js.strip().encode('utf-8'))
print js
print type(out_js)