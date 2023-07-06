#include <stdio.h>

int abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int find_gcd(int n, int num)
{
	if (num == 0)
		return (n);
	return (find_gcd(num, n%num));
}

int main() {
	int N,S,D;
	scanf("%d %d", &N, &S);

	int A[N];
	for (int i=0; i<N; i++) {
		scanf("%d", &A[i]);
		A[i] = abs(S - A[i]);
	}
	if (N == 1)
		D = A[0];
	else {
		D = find_gcd(A[0], A[1]);
		for (int i=2; i<N; i++)
			D = find_gcd(D, A[i]);
	}
	printf("%d\n", D);
	return 0;	
}