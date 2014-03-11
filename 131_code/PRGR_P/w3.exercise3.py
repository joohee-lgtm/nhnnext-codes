'''
NEXT 131
programming_practice
week3
exercise3
'''

def newNumber (number) :
	if 0 < number < 10 :
		return number + 10
	
	elif 10 < number < 100 :
		return number*0.1
	
	else :
		return False
		
input_n = input("input number")
result = newNumber(input_n)	
print result