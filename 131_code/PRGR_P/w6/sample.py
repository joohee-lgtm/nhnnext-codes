log_sample = '[Sun Dec 30 18:19:58 2012] [error] [client ::1] File does not exist: /Library/WebServer/Documents/favicon.ico'

splited_log = log_sample.split()
new_log = []

for i in splited_log :
	new = i.strip('[]')
	new_log.append(new)

address = len(new_log)

if 'error' in new_log :
	print new_log[address-1]