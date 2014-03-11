age_data = {'minsu' : 43 , 'jisu':33 , 'john' : 21 , 'david' : 33, 'hary':36, 'messi' :33, 'ronaldo' : 27, 'kkk' : 67}

new_dict = {}

def sortAge(age) :
	age0s = age/10
	return str(age0s) + '0s'

def sortData(age_data,new_dict) :
	for name in age_data :
		temp = sortAge(age_data[name])
		if temp in new_dict :
			new_dict[temp].append(name)
		else :
			new_dict[temp] = []
			new_dict[temp].append(name)

sortData(age_data,new_dict)
print new_dict
