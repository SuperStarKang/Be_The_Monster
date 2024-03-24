#include <iostream>

using namespace std;

int solutions[100001];
int result[2];

void	merge(int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int L[n1], R[n2];
	for (int i=0; i<n1; i++) {
		L[i] = solutions[left + i];
	}
	for (int i=0; i<n2; i++) {
		R[i] = solutions[mid + 1 + i];
	}

	int i = 0, j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			solutions[k++] = L[i++];
		else
			solutions[k++] = R[j++];
	}

	while (i < n1) {
		solutions[k++] = L[i++];
	}
	while (j < n2) {
		solutions[k++] = R[j++];
	}
}

void	merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid+1, right);
		merge(left, mid, right);
	}
}

int main(void) {
	int N;
	cin>>N;

	for (int i=0; i<N; i++)
		cin>>solutions[i];
	merge_sort(0, N-1);

	int left=0, right=N-1;
	int min = 2147483647;

	while (left < right) {
		int sum = solutions[left] + solutions[right];

		if (abs(sum) < min) {
			min = abs(sum);
			result[0] = solutions[left];
			result[1] = solutions[right];
		}

		if (sum < 0)
			left++;
		else
			right--;
	}
	cout<<result[0]<<' '<<result[1]<<endl;
	return 0;
}