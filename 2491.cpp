#include <iostream>

using namespace std;

int arr[100001];
int length[100001];

int main(void) {
	int N;
	cin>>N;

	for (int i=0; i<N; i++)
		cin>>arr[i];

	int up=1;
	int down=1;
	int idx=0;
	for (int i=0; i<N-1; i++) {
		if (arr[i] < arr[i+1]) {
			length[idx++] = down; 
			up++;
			down = 1;
		}
		else if (arr[i] > arr[i+1]) {
			length[idx++] = up;
			up = 1;
			down++;
		}
		else {
			up++;
			down++;
		}
	}
	length[idx++] = up;
	length[idx++] = down;

	int max = 0;
	for (int i=0; i<idx; i++) {
		if (max < length[i])
			max = length[i];
	}
	cout<<max<<endl;
	return 0;
}