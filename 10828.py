import sys

N = int(sys.stdin.readline())

stack = []
answer = []

for i in range(0,N):
    order = sys.stdin.readline().rstrip().split()
    command = order[0]
    if command == 'pop':
        if len(stack) > 0:
            answer.append(stack.pop(len(stack)-1))
        else:
            answer.append(-1)
    elif command == 'size':
        answer.append(len(stack))
    elif command == 'empty':
        if len(stack) > 0:
            answer.append(0)
        else:
            answer.append(1)
    elif command == 'top':
        if len(stack) > 0:
             answer.append(stack[len(stack)-1])
        else:
            answer.append(-1)
    else:
        stack.append(int(order[1]))

for i in range(0,len(answer)):
    print(answer[i])