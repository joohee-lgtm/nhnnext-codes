'''
NEXT 131
programming_practice
week3
exercise4
'''

import math

def distance(x1,x2,y1,y2) :
	return math.sqrt((x1-x2)**2+(y1-y2)**2)
	
x1 = input("x1")
x2 = input("x2")
y1 = input("y1")
y2 = input("y2")

result = distance(x1,x2,y1,y2)
print result