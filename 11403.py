N = int(input())

graph = []

for i in range(N):
	graph.append(list(map(int, input().split(" "))))

result = [[0 for col in range(N)] for row in range(N)]

stack = []

def print_result():
	for i in range(N):
		for j in range(N):
			print(result[i][j], end=" ")
		print()

def recur(n, next):
	for i in range(N):
		if graph[next][i] == 1 and result[n][i] == 0:
			result[n][i] = 1
			stack.append(i)
	if not stack:
		return
	next = stack.pop()
	recur(n,next)

for n in range(N):
	stack.append(n)
	recur(n, n)
	stack = []

print_result()