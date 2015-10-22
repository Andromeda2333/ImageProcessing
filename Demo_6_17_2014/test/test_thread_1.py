#coding=utf-8
'''
Created on 2014年7月12日

@author: lenovo
'''
import time  
import threading  
from mutex import mutex
from itertools import count
# def timer(no, interval):  
#     cnt = 0  
#     while cnt<10:  
#         print 'Thread:(%d) Time:%s\n'%(no, time.ctime())  
#         time.sleep(interval)  
#         cnt+=1  
#     threading. 
#      
#    
# def test(): #Use thread.start_new_thread() to create 2 new threads  
#     threading.start_new_thread(timer, (1,1))  
#     threading.start_new_thread(timer, (2,2))  
#    
# if __name__=='__main__':  
#     test()  
class Test(threading.Thread):
    def __init__(self,num):
        threading.Thread.__init__(self)
        self.runNum=num
    
    def run(self):
        global count,mutex
        threadName=threading.current_thread().getName()
        
        for x in xrange(0,int(self.runNum)):
            mutex.acquire()
            count=count+1
            mutex.release()
            print threadName,x,count
            time.sleep(1)
if __name__=='__main__':
    global count,mutex
    threads=[]
    num=4
    count=1
    mutex=threading.Lock()
    for x in xrange(0,num):
        threads.append(Test(10))
    
    for t in threads:
        t.start()
    for t in threads:
        t.join()
