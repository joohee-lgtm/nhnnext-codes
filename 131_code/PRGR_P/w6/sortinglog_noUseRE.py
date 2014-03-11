# -*- coding:utf-8 -*-

errorFile = open('error_log')

#주소 예1
#[Sun Dec 30 18:19:58 2012] [error] [client ::1] File does not exist: /Library/WebServer/Documents/favicon.ico

#주소 예2
#[Sun Dec 30 21:08:41 2012] [error] [client 127.0.0.1] File does not exist: /Library/WebServer/Documents/delivery, referer: http://news.hankooki.com/ad/hk_ad_page_250250.htm

#대괄호 제거한 log 리스트 만들기
def stripedLog(line) :
	splited_log = line.split()
	new_log = []
	for i in splited_log :
		new = i.strip('[]')
		new_log.append(new)
	print new_log
	return new_log


#리스트에서 에러 주소의 위치 확인
def getAddress(new_log) :
	if 'referer:' in new_log :
		return len(new_log)-3
	else :
		return len(new_log)-1


#에러key(=에러 종류)확인 후, 에러value(=에러 주소) 추가하기
def appendToDict(error_key,error_value,sorted_dict) :
	if error_key in sorted_dict :
		if error_value not in sorted_dict[error_key] :
			sorted_dict[error_key].append(error_value)
	else :
		sorted_dict[error_key] = []
		sorted_dict[error_key].append(error_value)


#에러value의 갯수 확인용 함수
def countDict(error_key,error_value,count_dict) :
	if error_key in count_dict :
		count_dict[error_key].append(error_value)
	else :
		count_dict[error_key] = []
		count_dict[error_key].append(error_value)


#main함수

sorted_dict = {}
count_dict = {}

for line in errorFile :
	
	new_log = stripedLog(line)
	
	if 'error' in new_log:
		
		address = getAddress(new_log)
		
		error_key = str(" ".join(new_log[8:address]))
		error_value = str(" ".join(new_log[address: ]))
		
		appendToDict(error_key,error_value,sorted_dict)
		countDict(error_key,error_value,count_dict)	

#확인
print "[summary report]"
for error_key in count_dict :
	print error_key , len(count_dict[error_key]) ,'개'

print " "
print " "
print " "

print "[detail report]"

number = 1
for error_key in sorted_dict :
	print "-------------------------------------------------------"
	print number,'.',error_key[:-1]
	for error_value in sorted_dict[error_key] :
		print error_value
	number = number + 1
