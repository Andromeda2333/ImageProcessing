#coding=utf-8
'''
Created on 2014年7月2日

@author: lenovo
'''
import numpy as np
import matplotlib.pyplot as plt
for idx,color in enumerate('rgbyck'):
    plt.subplot(3,2,1+idx,axisbg=color)
plt.show()