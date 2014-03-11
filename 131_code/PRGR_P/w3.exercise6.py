'''
NEXT 131
programming_practice
week3
exercise5
'''

string_sample = raw_input("input string")

check_back_string = -1
for char in string_sample :
	if string_sample[check_back_string] != char :
		break;
	else :
		check_back_string = check_back_string -1;

if (check_back_string+1)*-1 == len(string_sample) :
	print 'same'
else :
	print 'different'