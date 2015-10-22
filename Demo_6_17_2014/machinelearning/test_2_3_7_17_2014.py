#coding=utf-8
'''
Created on 2014年7月17日

@author: lenovo
'''
import numpy as np
from dircache import listdir
import operator

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

def img2vector(fileName):
    returnVect=np.zeros((1,1024))
    fr=open(fileName)
    for i in range(32):
        lineStr=fr.readline()
        for j in range(32):
            returnVect[0,32*i+j]=float(lineStr[j])
    return returnVect

def handwritingClassTest():
    hwLabels=[]
    trainingFileList=listdir('trainingDigits')
    m=len(trainingFileList)
    trainingMat=np.zeros((m,1024))
    
    for i in range(m):
        fileNameStr=trainingFileList[i]
        fileStr=fileNameStr.split('.')[0]
        classNumStr=int(fileStr.split('_')[0])
        hwLabels.append(classNumStr)
        trainingMat[i,:]=img2vector('trainingDigits/%s' % fileNameStr)
    
    testFileList=listdir('testDigits')
    errorCount=0.0
    mTest=len(testFileList)
    
    for i in range(mTest):
        fileNameStr=testFileList[i]
        fileStr=fileNameStr.split('.')[0]
        classNumStr=int(fileStr.split('_')[0])
        vectorUnderTest=img2vector('testDigits/%s' % fileNameStr)
        classifierResult=classify0(vectorUnderTest,
                                   trainingMat,
                                   hwLabels,3)
#         print '分类器返回的结果是： %d ,真实结果是  %d' % (classifierResult,classNumStr) 
        if classifierResult!=classNumStr:
            errorCount+=1.0
    print '发生错误的总数是  %d'% errorCount
    print '总错误率为 %f'% (errorCount/float(mTest)) 


handwritingClassTest()
