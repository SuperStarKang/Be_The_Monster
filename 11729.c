#include <stdio.h>
#include <math.h>

void	hanoi(int N, char from, char tmp, char to) {
	if (N == 1) {
		printf("%c %c\n", from, to);
		return ;
	}
	else {
		hanoi(N-1, from, to ,tmp);
		printf("%c %c\n", from, to);
		hanoi(N-1, tmp, from, to);
	}
}

int main(void) {
	int N;
	scanf("%d", &N);

	int count[N];
	count[0] = 1;
	for (int i=1; i<N; i++) {
		count[i] = count[i-1] + pow(2, i);
	}
	printf("%d\n", count[N-1]);
	hanoi(N, '1', '2', '3');

	return 0;
}