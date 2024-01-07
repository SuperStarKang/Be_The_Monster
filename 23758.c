#include <stdio.h>

int sorted[10000000];

int result(int *arr, int idx, int N) {
	int cnt = 0;

	while (1) {
		if (arr[idx] == 1)
			return (cnt+1);

		arr[idx] /= 2;

		cnt += 1;

		int tmp = arr[idx];
		int i = idx;
		for (; i>0 && tmp < arr[i-1]; i--) {
			arr[i] = arr[i-1];
		}
		arr[i] = tmp;
	}
	return (cnt);
}

void	merge(int list[], int left, int mid, int right){
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	if (i > mid) {
		for (l=j; l<=right; l++)
			sorted[k++] = list[l];
	}
	else {
		for (l=i; l<=mid; l++)
			sorted[k++] = list[l];
	}

	for(l=left; l<=right; l++) {
		list[l] = sorted[l];
	}
}

void	merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left+right)/2;
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}

int main(void) {
	int N;
	scanf("%d", &N);

	int arr[N];
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	int idx;
	if (N % 2 == 0)
		idx = N / 2 - 1;
	else
		idx = N / 2;

	merge_sort(arr, 0, N-1);
	printf("%d\n", result(arr, idx, N));
	return 0;
}