#coding=utf-8
'''
Created on 2014年7月22日

@author: lenovo
'''
import paramiko 
hostname='172.16.22.23' 
port=22 
username='root' 
password='larryroot' 
if __name__=="__main__": 
        s=paramiko.SSHClient() 
        s.set_missing_host_key_policy(paramiko.AutoAddPolicy()) 
        s.connect(hostname,port,username,password) 
        stdin,stdout,sterr=s.exec_command('df -Th') 
        print stdout.read() 
        s.close() 

