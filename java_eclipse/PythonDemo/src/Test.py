﻿# -*- coding: utf-8 -*-
'''
Created on 2015年3月8日

@author: lenovo
'''
import numpy as np
import matplotlib.pyplot as plt
a=np.array([1,2,3,4,5,6])
print np.max(a)

x=np.linspace(0, 10, 1000)
y=np.sin(x)
z=np.cos(x**2)
plt.figure(figsize=(8,4))
plt.plot(x,y)
plt.plot(x,z)
plt.show()