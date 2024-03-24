#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N;
	scanf("%d", &N);

	int arr[N];
	for (int i=0; i<N; i++)
		scanf("%d", &arr[N]);

	int card[5] = {1,2,3,4,5};
	for (int i=0; i<N; i++) {
		if (arr[i] == 1) {
			card[i] = 5 - i;
		}
		else if (arr[i] == 2) {
			card[i - 1] = i + 1;
		}
		else if (arr[i] == 3) {
			card[i] = 5 - i;
		}
	}

	for (int i=0; i<5; i++)
		printf("%d ", card[i]);
	printf("\n");
	return 0;
}