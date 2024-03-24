#include <iostream>

using namespace std;

char board[51][51];

int	count(int x, int y) {
	int cnt0=0,cnt1=0;
	for (int n=0; n<8; n++) {
		if (n % 2 == 0) {
			for (int m=0; m<8; m++) {
				if (m % 2 == 0) {
					if (board[y+n][x+m] != 'W')
						cnt0++;
					if (board[y+n][x+m] != 'B')
						cnt1++;
				}
				else {
					if (board[y+n][x+m] != 'B')
						cnt0++;
					if (board[y+n][x+m] != 'W')
						cnt1++;
				}
			}
		}
		else {
			for (int m=0; m<8; m++) {
				if (m % 2 == 0) {
					if (board[y+n][x+m] != 'B')
						cnt0++;
					if (board[y+n][x+m] != 'W')
						cnt1++;
				}
				else {
					if (board[y+n][x+m] != 'W')
						cnt0++;
					if (board[y+n][x+m] != 'B')
						cnt1++;
				}
			}	
		}
	}
	if (cnt0 < cnt1)
		return cnt0;
	return cnt1;
}

int main(void) {
	int N,M;
	cin>>N>>M;

	for (int i=0; i<N; i++) {
		cin>>board[i];
	}

	int min=2147483647;
	for (int i=0; i<=N-8; i++) {
		int tmp;
		for (int j=0; j<=M-8; j++) {
			tmp = count(j, i);
			if (min > tmp)
				min = tmp;
		}
	}
	cout<<min<<endl;
	return 0;
}
