#coding=utf-8
'''
Created on 2014年6月25日

@author: lenovo
'''
import pickle
'''
利用pickle把数据存入datafile.pkl中
'''

D={'a':1,'b':2}
F=open('datafile.pkl','w')
pickle.dump(D,F)
F.close

'''
读取datafile.pkl中的数据,
但是数据的类型不是str
'''
F=open('datafile.pkl','r')
E=pickle.load(F)
print E
print type(E)

L=[x for x in range(10)]
X=L[3:5]
print X
X[0]=324
print X
print L




