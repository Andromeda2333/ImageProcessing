#coding=utf-8
'''
Created on 2014年6月17日

@author: lenovo
'''
f=open('C:\Users\lenovo\Desktop\data1.txt','w')
f.write("str"+'hello world\n')
f.write('你好啊!!!')
f.close()

fr=open('C:\Users\lenovo\Desktop\data.txt','r')
text=fr.read()
print text
print text.split()[0:-1]