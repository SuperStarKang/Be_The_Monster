#include <iostream>

using namespace std;

int arr[1001];
int up[1001];
int down[1001];

int main(void) {
	int N;
	cin>>N;

	int min=10000;
	for (int i=0; i<N; i++) {
		cin>>arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	up[0] = 1;
	for (int i=1; i<N; i++) {
		int same=0;
		int small=0;
		for (int k=i-1; k>=0; k--) {
			if (arr[k] == arr[i]) {
				if (same < up[k])
					same = up[k];
			}
			if (arr[k] < arr[i]) {
				if (small < up[k])
					small = up[k];
			}
		}
		if (same > small) {
			up[i] = same;
		}
		else {
			up[i] = small+1;
		}
	}

	down[N-1] = 1;
	for (int i=N-2; i>=0; i--) {
		int same=0;
		int big=0;
		for (int k=i+1; k<N; k++) {
			if (arr[k] == arr[i]) {
				if (same < down[k])
					same = down[k];
			}
			if (arr[k] < arr[i]) {
				if (big < down[k])
					big = down[k];
			}
		}
		if (same > big) {
			down[i] = same;
		}
		else {
			down[i] = big+1;
		}
	}

	int max=0;
	for (int i=0; i<N; i++) {
		// cout<<"up : "<<up[i]<<" down : "<<down[i]<<endl;
		if (max < up[i] + down[i]-1)
			max = up[i] + down[i]-1;
	}
	cout<<max<<endl;

	return 0;
}