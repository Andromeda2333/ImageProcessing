#coding=utf-8
'''
Created on 2014年7月21日

@author: lenovo
'''
import socket
s=socket.socket()
host=socket.gethostname()
port=12345
s.bind((host,port))

s.listen(5)
while True:
    c,addr=s.accept()
    print 'Got cnnection from',addr
    c.send('Thank you for connecting')
    c.close()
