# -*- coding:utf-8 -*-
import re

#--------------used fuction--------------#


#각 라인마다 에러종류와 에러주소만 추출하기
def getErrLog(log_line) :
	result = re.search(']\s\w+.*',log_line)
	return str(result.group())[2:]


#에러종류 구분하기
def getErrType(new_line) :
	if ":" in new_line :
		result = re.search('^.*:\s/',new_line)
		return str(result.group())[:-3]
	else :
		return new_line

#에러주소 추출하기
def getErrAddr(new_line) :
	if "/" in new_line :
		result = re.search('/.*',new_line)
		return str(result.group())
	else :
		return 'none'


# 에러주소를 에러종류에 맞게 딕셔너리에 분류하기
# error_key : 에러종류 / error_value : 에러주소
def appendToDict(err_key,err_value,sorted_dict) :
	if err_key in sorted_dict :
		if err_value not in sorted_dict[err_key] :
			sorted_dict[err_key].append(err_value)
	else :
		sorted_dict[err_key] = []
		sorted_dict[err_key].append(err_value)


# 에러종류 마다 갖고 있는 에러주소의 갯수 구하기
def countDict(err_key,err_value,count_dict) :
	if err_key in count_dict :
		count_dict[err_key].append(err_value)
	else :
		count_dict[err_key] = []
		count_dict[err_key].append(err_value)


# 에러 주소에서 이미지 파일명을 제거하기
def checkIMG(addr):
	front = re.search('.*\w+/(?=(\w+.(jpg|png|gif)))',addr)
	rear = re.search('(?<=(.(jpg|png|gif))).*',addr)
	return str(front.group()) + str(rear.group())



#--------------main function--------------#

errorFile = open('w6.error_log')

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
for err_key in count_dict :
	print err_key, len(count_dict[err_key]) , '개'

print " "
print " "
print " "

print "[detail report]"
print " "

number = 1

for err_key in sorted_dict :
	print "-------------------------------------------------------"
	print number,'.',err_key
	for err_value in sorted_dict[err_key] :
		if '.jpg' in err_value or '.png' in err_value or '.gif' in err_value :
			print checkIMG(err_value)
		else :
			print err_value
	number = number + 1

