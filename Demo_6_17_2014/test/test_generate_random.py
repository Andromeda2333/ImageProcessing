#coding=utf-8
'''
Created on 2014年6月19日

@author: lenovo
'''
import random
from random import randint, seed
from __builtin__ import len

def geneRandom(m,n):
    vec=[x for x in range(n)]
    res=[]
    tag=n-1
    
    for i in range(0,m):
        index=randint(0,tag)
        temp=vec[tag]
        vec[tag]=vec[index]
        vec[index]=temp
        res.append(vec[tag])
        tag-=1
    return res

res=geneRandom(298, 300)
S=set(res)
print len(res),len(S)
print res
print S


