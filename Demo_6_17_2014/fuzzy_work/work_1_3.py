#coding=utf-8
'''
Created on 2014年7月1日

@author: lenovo
'''
import numpy as np
A=[.5,.1,0,1,.8]
B=[.1,.4,.9,.7,.2]
C=[.8,.2,1,.4,.3]
A=np.array(A)
B=np.array(B)
C=np.array(C)

ANS1=np.maximum(A,B)
ANS2=np.minimum(A,B)
ANS3=np.minimum(ANS1,C)
ANS4=1-A

print ANS1
print ANS2
print ANS3
print ANS4

