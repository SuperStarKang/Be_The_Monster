#include <iostream>
#include <cmath>
#include <unistd.h>

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

int	binary_search(int left, int right, int num, int sum) {
	int min=sum;

	while (left <= right) {
		int mid = (left+right)/2;

		if (abs(num + solutions[mid]) < min) {
			min = abs(num + solutions[mid]);
			result[0] = num;
			result[1] = solutions[mid];
		}

		if (num + solutions[mid] > 0) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return min;
}

// int	binary_search(int N, int target, int idx, int sum) {
// 	int low = idx+1;
// 	int high = N-1;
// 	int mid;
// 	int min = sum;

// 	while (low <= high) {
// 		mid = (low+high)/2;
// 		if (abs(solutions[mid] + target) > min) {
// 			if (abs(target) > abs(solutions[mid])) {
// 				high = mid - 1;
// 			}
// 			else {
// 				low = mid + 1;
// 			}
// 		}
// 		else {
// 			min = abs(solutions[mid] + target);
// 			result[0] = target;
// 			result[1] = solutions[mid];
// 			if (abs(target) > abs(solutions[mid])) {
// 				low = mid + 1;
// 			}
// 			else {
// 				high = mid - 1;
// 			}
// 		}
// 	}
// 	return min;
// }

int main(void) {
	int N;
	cin>>N;

	for (int i=0; i<N; i++)
		cin>>solutions[i];
	merge_sort(0, N-1);

	int target;
	int min=2147483647;
	for (int i=0; i<N; i++) {
		int sum = binary_search(i+1,N-1,solutions[i],min);
		if (min > sum)
			min = sum;
	}
	cout<<result[0]<<' '<<result[1]<<endl;
	return 0;
}
