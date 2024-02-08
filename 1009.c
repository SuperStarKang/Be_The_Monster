#include <stdio.h>

int main(void) {
	int T;
	scanf("%d", &T);

	int a,b;
	int tmp;
	int num;
	for (int i=0; i<T; i++) {
		scanf("%d %d", &a, &b);
		tmp = a;
		for (int j=1; j<b; j++) {
			a = (a*tmp) % 10;
		}
		num = a % 10;
		if (num == 0)
			printf("10\n");
		else
			printf("%d\n", num);
	}

	return 0;
}