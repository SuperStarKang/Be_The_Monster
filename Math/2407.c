#include <stdio.h>

int main() {
	int n,m;
	unsigned long long result=1;

	scanf("%d %d", &n, &m);

	for (int i=0; i<m; i++)
		result *= n-i;
	for (int i=0; i<m; i++)
		result /= i+1;

	printf("%llu\n", result);

	return 0;
}