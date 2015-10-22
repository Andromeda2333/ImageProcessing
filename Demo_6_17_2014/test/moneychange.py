#coding=utf-8
'''
Created on 2014年6月19日

@author: lenovo
'''
def Charge(y):
    x=[1,2,5,10,20,50,100]
    z=[]
    for i in range(0,y+1,1):
        if i in x:
            z.append(1)
        else:
            z.append(0)
    for i in range(2,y+1,1):
        temp=[]
        for j in range(0,i,1):
            if z[i-j]+z[j]!=0:
                temp.append(z[i-j]+z[j])
        z[i]=min(temp)
    return z[y]

money=329

print 'money=%d charge with %d'%(money,Charge(money))