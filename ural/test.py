import numpy as np


x1 = 150*100/(100+100+150+1.0/3)
x2 = x1
x3 = 150*150/(100+100+150+1.0/3)
x4 = 1.0/3


print x1, x2, x3, x4


print (x1*1000 + x2*750 + x3*585 + x4*0)/(1000.0 * 150)
