# -*- coding:utf-8 -*-
import re

#--------------used fuction--------------#

def getErrLog(log_line) :
	result = re.search(']\s\w+.*',log_line)
	return str(result.group())[2:]

def getErrType(new_line) :
	if ":" in new_line :
		result = re.search('^.*:\s/',new_line)
		return str(result.group())[:-3]
	else :
		return new_line

def getErrAddr(new_line) :
	if "/" in new_line :
		result = re.search('/.*',new_line)
		return str(result.group())
	else :
		return 'none'

def appendToDict(error_key,error_value,sorted_dict) :
	if error_key in sorted_dict :
		if error_value not in sorted_dict[error_key] :
			sorted_dict[error_key].append(error_value)
	else :
		sorted_dict[error_key] = []
		sorted_dict[error_key].append(error_value)


def countDict(err_key,error_value,count_dict) :
	if err_key in count_dict :
		count_dict[err_key].append(err_value)
	else :
		count_dict[err_key] = []
		count_dict[err_key].append(err_value)

def checkIMG(addr):
	front = re.search('.*\w+/(?=(\w+.(jpg|png|gif)))',addr)
	rear = re.search('(?<=(.(jpg|png|gif))).*',addr)
	return str(front.group()), str(rear.group())



#--------------main function--------------#

errorFile = open('error_log')

sorted_dict = {}
count_dict = {}

for line in errorFile :

	if 'error' in line:
		
		new_line = getErrLog(line)
		
		err_key = getErrType(new_line)
		err_value = getErrAddr(new_line)
		
		appendToDict(err_key,err_value,sorted_dict)
		countDict(err_key,err_value,count_dict)




#--------------print result--------------#

print "[summary report]"
for error_key in count_dict :
	print error_key, len(count_dict[error_key]) , '개'

print " "
print " "
print " "

print "[detail report]"
print " "

number = 1

for error_key in sorted_dict :
	print "-------------------------------------------------------"
	print number,'.',error_key
	for error_value in sorted_dict[error_key] :
		if '.jpg' in error_value or '.png' in error_value or '.gif' in error_value :
			print checkIMG(error_value)
		else :
			print error_value
	number = number + 1

