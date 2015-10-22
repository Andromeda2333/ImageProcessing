#coding=utf-8
'''
Created on 2014年7月16日

@author: lenovo
'''
import numpy as np
import matplotlib.pyplot as plt
import operator

def createDataSet():
    group=np.array([[1,1.1],[1,1],[0,0],[0,.1]])
    labels=['A','A','B','B']
    return group,labels
def classify0(inX,dataSet,labels,k):
    dataSetSize=dataSet.shape[0]
    diffMat=np.tile(inX,(dataSetSize,1))-dataSet
    sqDiffMat=diffMat**2
    sqDistances=sqDiffMat.sum(1)
    distances=sqDistances**0.5
    sortedDistIndicies=distances.argsort()
    classCount={}
    for i in range(k):
        voteIlabel=labels[sortedDistIndicies[i]]
        classCount[voteIlabel]=classCount.get(voteIlabel,0)+1
    sortedClasscount=sorted(classCount.iteritems(),
                            key=operator.itemgetter(1),
                            reverse=True)
    return sortedClasscount[0][0]
    
def file2matrix(filename):
    fr=open(filename)
    arrayOLines=fr.readlines()
    numberOfLines=len(arrayOLines)
    returnMat=np.zeros((numberOfLines,3))
    classLabelVector=[]
    index=0
    for line in arrayOLines:
        line=line.strip()
        listFromLine=line.split('\t')
        returnMat[index,:]=listFromLine[0:3] 
        classLabelVector.append(int(listFromLine[-1]))
        index+=1
    return returnMat,classLabelVector
def autoNorm(dataSet):
    minVals=dataSet.min(0)
    maxVals=dataSet.max(0)
    ranges=maxVals-minVals
    normDataSet=np.zeros(dataSet.shape)
    m=dataSet.shape[0]
    normDataSet=dataSet-np.tile(minVals,(m,1))
    normDataSet=normDataSet/np.tile(ranges,(m,1))
    return normDataSet,ranges,minVals

def datingClassTest():
    hoRatio=0.10
    datingDataMat,datingLabels=file2matrix('datingTestSet2.txt')
    normMat,ranges,minVals=autoNorm(datingDataMat)
    m=normMat.shape[0]
    numTestVecs=int(m*hoRatio)
    errorCount=0.0
    for i in range(numTestVecs):
        classifierResult=classify0(normMat[i,:],
                                    normMat[numTestVecs:m,:],
                                    datingLabels[numTestVecs:m],
                                    3)
        print 'the classifier came back with: %d,the real answer is %d'\
                %(classifierResult,datingLabels[i])
        if classifierResult!=datingLabels[i]:
           errorCount+=1
    print 'the total error rate is : %f'%(errorCount/float(numTestVecs)) 
    
def classifyPerson():
    resultList=['not at all','in small doses','in large doses']
    percentTats=float(raw_input('percentage of time spent playing video games?'))
    ffMiles=float(raw_input('fequent flier miles earned per year?'))
    iceCream=float(raw_input('liters of ice cream consumed per year?'))
    datingDataMat,datingLabels=file2matrix('datingTestSet2.txt')
    nornMat,ranges,minVals=autoNorm(datingDataMat)
    inArr=np.array([ffMiles,percentTats,iceCream])
    classifierResult=classify0((inArr-minVals)/ranges, nornMat, datingLabels, 3)
    print 'you will probably like this person: ',resultList[classifierResult-1]
        
datingdataMat,datingLabels=file2matrix('datingTestSet2.txt')
fig=plt.figure()
datingdataMat,ranges,minVals=autoNorm(datingdataMat)
# plt.plot(datingdataMat[:,1],datingdataMat[:,2],'o')
ax=fig.add_subplot(111)
# ax.scatter(datingdataMat[:,1],datingdataMat[:,2])
ax.scatter(datingdataMat[:,0],datingdataMat[:,1],
           15.0*np.array(datingLabels),15.0*np.array(datingLabels))
plt.show()
# print datingdataMat

# datingClassTest()
classifyPerson()