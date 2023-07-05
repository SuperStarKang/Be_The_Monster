#include <stdio.h>

void print_arr(int *arr, int N)
{
	for (int i=0; i<N; i++)
	{
		if (i != N-1)
			printf("%d ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}
}

void swap(int *arr, int i, int j)
{
	int tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void permutation(int *arr, int N, int depth)
{
	// int count = 0;

	if (depth == N-1) {
		print_arr(arr, N);
		return ;
	}

	for (int i=depth; i<N; i++) {
		swap(arr, i, depth);
		permutation(arr, N, depth+1);
		// count++;
		swap(arr, i , depth);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int arr[N];

	for (int i=0; i<N; i++)
		arr[i] = i+1;

	permutation(arr, N, 0);
	
	return (0);
}