#include <iostream>

using namespace std;

int arr[51];

void	merge(int left, int mid, int right) {
	int n1 = mid-left+1;
	int n2 = right-mid;

	int L[n1],R[n2];
	for (int i=0; i<n1; i++)
		L[i] = arr[left+i];
	for (int i=0; i<n2; i++)
		R[i] = arr[mid+1+i];
	
	int i=0,j=0;
	int k=left;
	while (i<n1 && j<n2) {
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
}

void	merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left+right)/2;
		merge_sort(left, mid);
		merge_sort(mid+1,right);
		merge(left, mid, right);
	}
}

int main(void) {
	int N;
	cin>>N;

	int negative=0,postive=0;
	int has_zero=0;
	int num;
	int idx=0;
	for (int i=0; i<N; i++) {
		cin>>num;
		if (num == 0)
			has_zero = 1;
		else {
			arr[idx++] = num;
			if (num < 0)
				negative++;
			else if (num > 0)
				postive++;
		}
	}
	merge_sort(0,negative + postive - 1);

	long long result = 0;
	int i=0;
	if (negative % 2 == 0) {
		for (i=0; i < negative-1; i += 2) {
			result += arr[i] * arr[i+1];
		}
	}
	else {
		for (i=0; i<negative-1; i+=2) {
			result += arr[i] * arr[i+1];
		}
		i++;
		if (has_zero == 0)
			result += arr[negative-1];
	}

	if (postive % 2 == 0) {
		for (int j=negative+postive-1; j>i; j -= 2)
			if (arr[j-1] == 1)
				result += arr[j] + arr[j-1];
			else
				result += arr[j] * arr[j-1];
	}
	else {
		for (int j=negative+postive-1; j>i; j -= 2)
			if (arr[j-1] == 1)
				result += arr[j] + arr[j-1];
			else
				result += arr[j]*arr[j-1];
		result += arr[i];
	}

	cout<<result<<endl;
	return 0;
}
