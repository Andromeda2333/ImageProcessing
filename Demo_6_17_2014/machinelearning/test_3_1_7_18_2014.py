#coding=utf-8
'''
Created on 2014年7月18日

@author: lenovo
'''
from math import log
def calcShannonEnt(dataSet):
    m=len(dataSet)
    labelCounts={}
    
    for elem in dataSet:
        currentLabel=elem[-1]
        labelCounts[currentLabel]=labelCounts.get(currentLabel,0)+1
    
    shannonEnt=0
    for key in labelCounts:
        prob=float(labelCounts[key])/m
        shannonEnt-=prob*log(prob,2)
    return shannonEnt

def createDataSet():
    dataSet=[[1,1,'yes'],
             [1,1,'yes'],
             [1,0,'no'],
             [0,1,'no'],
             [0,1,'no']]
    labels=['no surfacing','flippers']
    return dataSet,labels

def splitData(dataSet,index,value):
    reDataSet=list()
    for ele in dataSet:
        if ele[index]==value:
            reduceVEle=ele[:index]
            reduceVEle.extend(ele[index+1:])
            reDataSet.append(reduceVEle)
    return reDataSet

myData,labels=createDataSet()
print myData,labels
print calcShannonEnt(myData)
print splitData(myData,0, 1)
print splitData(myData,0, 0)