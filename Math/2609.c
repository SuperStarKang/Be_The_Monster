#include <stdio.h>

int find_gcd(int N, int M)
{
	int gcd;

	if (N>M) {
		for (int i=1; i<=M; i++) {
			if (N%i == 0 && M%i == 0)
				gcd = i;
		}
	}
	else {
		for (int i=1; i<=N; i++) {
			if (N%i == 0 && M%i == 0)
				gcd = i;
		}
	}
	return (gcd);
}

int find_lcm(int N, int M, int gcd)
{
	int lcm;
	int tmp;

	tmp = gcd;
	while(1) {
		if (gcd % N == 0 && gcd % M == 0) {
			lcm = gcd;
			return (lcm);
		}
		gcd += tmp;
	}
	return (lcm);
}

int main() {
	int N,M;
	int lcm,gcd;

	scanf("%d %d", &N, &M);

	if (N==M) {
		printf("%d\n%d\n", N, N);
		return (0);
	}

	gcd = find_gcd(N,M);
	lcm = find_lcm(N,M,gcd);

	printf("%d\n%d\n", gcd, lcm);
	return (0);
}