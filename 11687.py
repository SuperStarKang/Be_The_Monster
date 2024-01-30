M = int(input())

def cnt(M, cnt):
	if cnt == M:
		print(cnt*5)
		return
	elif cnt > M:
		print(-1)
		return
	else:
		tmp = M
		while tmp > 0:
			cnt += 1
			tmp /= 5

cnt(M, 1)