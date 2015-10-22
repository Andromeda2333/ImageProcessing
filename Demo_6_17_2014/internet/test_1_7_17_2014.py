#coding=utf-8
'''
Created on 2014年7月17日

@author: lenovo
'''
import socket ,sys
port=70
host=sys.argv[1]
fileName=sys.argv[2]

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((host,port))

s.sendall(fileName+'\r\n')

while 1:
    buf=s.recv(2048)
    if not len(buf):
        break
    sys.stdout.write(buf)