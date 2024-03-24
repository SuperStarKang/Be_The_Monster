#include <iostream>
#include <cmath>

using namespace std;

long long solutions[5001];
long long result[3];

void	merge(int left, int mid, int right) {
	int n1=mid-left+1,n2=right-mid;
	long long L[n1],R[n2];

	for (int i=0; i<n1; i++)
		L[i] = solutions[left+i];
	for (int i=0; i<n2; i++)
		R[i] = solutions[mid+1+i];
	
	int i=0,j=0;
	int k=left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			solutions[k++] = L[i++];
		else
			solutions[k++] = R[j++];
	}

	while (i<n1)
		solutions[k++] = L[i++];
	while (j<n2)
		solutions[k++] = R[j++];
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

	for (int i=0; i<N; i++)
		cin>>solutions[i];
	merge_sort(0,N-1);

	long long min=3000000001,sum;
	int i,l,r;
	for (i=0; i<N; i++) {
		l=i+1;
		r=N-1;
		while (l < r) {
			sum = solutions[i]+solutions[l]+solutions[r];
			if (min > abs(sum)) {
				min = abs(sum);
				result[0] = solutions[i];
				result[1] = solutions[l];
				result[2] = solutions[r];
			}
			if (sum < 0)
				l++;
			else
				r--;
		}
	}
	cout<<result[0]<<' '<<result[1]<<' '<<result[2]<<endl;
	return 0;
}
