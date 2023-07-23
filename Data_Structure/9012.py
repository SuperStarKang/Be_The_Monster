import sys

T = int(input())

for i in range(T):
	stack = []
	str = input()
	for j in range(len(str)):
		if str[j] == '(':
			stack.append(j)
		elif str[j] == ')':
			if len(stack) > 0:
				stack.pop()
			else:
				print("NO")
				break
		else:
			print("NO")
			break
		if j == len(str)-1:
			if len(stack) > 0:
				print("NO")
			else:
				print("YES")