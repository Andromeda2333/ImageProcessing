#coding=utf-8
'''
Created on 2014 6 20

@author: lenovo
'''
# 身高数据
u=[140,150,160,170,180,190]
# 高个子的隶属度
A=[(x-140)/(190-140.0) for x in u]
result={x:y for (x,y) in zip(u,A)}
print result
L=[(1,0),(2,0.2),(3,0.8),(4,1),(5,0.8),(6,0.2)]
print L