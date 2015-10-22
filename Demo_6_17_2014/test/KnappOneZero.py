#coding=utf-8
'''
Created on 2014年6月19日

@author: lenovo
'''
def Knapp(w,p,m):
    n=len(w)
    w=[0]+w
    p=[0]+p
    x=[0 for i in range(n+1)]
    optp=[]
    for i in range(n+1):
        optp.append([0 for t in range(m+1)])

    for j in range(1,m+1,1):
        for i in range(1,n+1,1):
            if j<w[i]:
                optp[i][j]=optp[i-1][j]
            else:
                optp[i][j]=max([optp[i-1][j],optp[i-1][j-w[i]]+p[i]])
    return optp[n][m]

    
    
w=[2,2,6,5,4]
p=[6,3,5,4,6]
print Knapp(w, p, 10)