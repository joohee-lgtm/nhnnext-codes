age_data = {'minsu' : 43 , 'jisu':33 , 'john' : 21 , 'david' : 33, 'hary':36, 'messi' :33, 'ronaldo' : 27}

new_dict = { '30s' : [] , '20s' : [] }
print new_dict

for name in age_data :
	if 20 <= age_data[name] < 30 :
		new_dict['20s'].append(name)
	elif 30 <= age_data[name] < 40 :
		new_dict['30s'].append(name)

print new_dict