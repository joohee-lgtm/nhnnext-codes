'''
NEXT 131
programming_practice
week3
exercise2
'''

def return_num (number) :
	if number < 0 :
		return number*-1
	else :
		return number
	

input_n = input("input number")
result = return_num(input_n)
print result