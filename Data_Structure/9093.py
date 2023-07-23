import sys

T = int(sys.stdin.readline())

for i in range(T):
    str = sys.stdin.readline().rstrip().split()
    for j in range(len(str)):
        print(str[j][::-1], end=" ")
    print()
    