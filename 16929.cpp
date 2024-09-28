#include <iostream>
#include <algorithm>

using namespace std;

int arr[301][301];
int result[301][301];

void	print(int N,int M) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
}

void	rotate(int idx, int width, int height, int R) {
	for (int cnt=0; cnt<R; cnt++) {
		int up_right=arr[idx][width-1-idx],down_right=arr[height-1-idx][width-1-idx];
		int up_left=arr[idx][idx],down_left=arr[height-1-idx][idx];
		for (int i=0; i<width-1 - 2*idx; i++) {
			arr[idx][idx + i] = arr[idx][idx + i + 1];
		}
		for (int i=0; i<height-1 - 2*idx; i++) {
			arr[height-1 - idx - i][idx] = arr[height-1 - idx - i - 1][idx];
		}
		arr[idx+1][idx] = up_left;
		for (int i=0; i<width-1 - 2*idx; i++) {
			arr[height-1 - idx][width-1-idx - i] = arr[height-1 - idx][width-1-idx - i - 1];
		}
		arr[height-1- idx][idx+1] = down_left;
		for (int i=0; i<height-1 - 2*idx; i++) {
			arr[idx + i][width-1-idx] =  arr[idx+i+1][width-1-idx];
		}
		arr[height-1-idx-1][width-1-idx] = down_right;
	}
}

int main(void) {
	int N,M,R;
	cin>>N>>M>>R;

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin>>arr[i][j];
		}
	}
	
	int cnt = min(N,M);
	for (int i=0; i<cnt/2; i++) {
		rotate(i, M, N, R);
	}
	print(N,M);
	return 0;
}