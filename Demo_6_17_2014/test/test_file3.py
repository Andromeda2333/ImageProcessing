#coding=utf-8
'''
Created on 2014年6月25日

@author: lenovo
'''
x,y,z=43,44,45
s='spam'
d={'a':1,'b':2}
l=[1,2,3]
f=open('datafile.txt','a')
f.write(s+'\n')
f.write('%s,%s,%s\n'%(x,y,z))
f.write(str(l)+'$'+str(d)+'\n')
f.close()

chars=open('datafile.txt','r').read()
print chars

print '-'*45
F=open('datafile.txt')
line=F.readline()
print(line)

