#coding=utf-8
'''
Created on 2014年7月15日

@author: lenovo
'''
def knn(p_set,p_tar):
    k=len(p_tar)
    n=len(p_set)
    error=100
    box=[list() for i in range(k)]
    
    while error>10**(-2):
        error=0
        for x in p_set:
            temp=[distance(x, y) for y in p_tar]
            i=temp.index(max(temp))
            box[i].append(x)
        for j in range(k):
            x1=0
            y1=0
            for elem in box[j]:
                x1=elem[0]+x1
                y1=elem[1]+y1
            if x1==0 and y1==0:
                continue
            p_tar[j]=[x1/len(box[j]),y1/len(box[j])]
            
        for l in range(k):
            for elem1 in box[l]:
                error=error+distance(p_tar[l], elem1)
            box[l]=[]
        return p_tar
              
def sub(x,y):
    return (x[0]-y[0],x[1]-y[1])
def distance(x,y):
    z=sub(x,y)
    return z[0]**2+z[1]**2
    
    
import random
import numpy as np
import matplotlib.pyplot as plt
p_set=list()
p_tar=list()

for x in range(2000):
    p_set.append([random.uniform(1,20),random.uniform(1,20)])
for x in range(10):
    p_tar.append([random.uniform(1,20),random.uniform(1,20)])
p_tar_copy=p_tar[:]
p_tar_result=knn(p_set, p_tar_copy)
p_tar_x_set1=[el1[0] for el1 in p_tar]
p_tar_y_set1=[el2[1] for el2 in p_tar]
p_tar_x_set2=[el3[0] for el3 in p_tar_result]
p_tar_y_set2=[el4[1] for el4 in p_tar_result]
p_set_x=[el5[0] for el5 in p_set]
p_set_y=[el6[1] for el6 in p_set]
plt.plot(p_set_x,p_set_y,'k.')
plt.plot(p_tar_x_set1,p_tar_y_set1,'ro')
plt.plot(p_tar_x_set2,p_tar_y_set2,'bo')
plt.show()
