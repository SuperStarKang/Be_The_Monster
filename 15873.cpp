str = input()

if str[0] == '1' and str[1] == '0':
	print(int(str[:2]) + int(str[2:]))
else:
	print(int(str[0]) + int(str[1:]))
