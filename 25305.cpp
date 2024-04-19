#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void merge(int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int L[n1], R[n2];
	for (int i=0; i<n1; i++) {
		L[i] = v[left + i];
	}
	for (int i=0; i<n2; i++) {
		R[i] = v[mid+1+i];
	}

	int i=0,j=0;
	int k=left;
	while (i < n1 && j < n2) {
		if (L[i] > R[j]) {
			v[k++] = L[i++];
		}
		else {
			v[k++] = R[j++];
		}
	}

	while (i < n1) {
		v[k++] = L[i++];
	}
	while (j < n2) {
		v[k++] = R[j++];
	}
}

void merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right)/2;
		merge_sort(left, mid);
		merge_sort(mid+1, right);
		merge(left, mid, right);
	}
}

int main(void) {
	int N,k;
	cin >> N >> k;

	int num;
	for (int i=0; i<N; i++) {
		cin >> num;
		v.push_back(num);
	}

	merge_sort(0,N-1);

	cout << v[k-1] << endl;

	return 0;
}