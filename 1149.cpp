#include <iostream>
#include <algorithm>

using namespace std;

int house[1001][3];
int dp[1001][3];

int main(void) {
	int N;
	cin>>N;

	for (int i=0; i<N; i++) {
		for (int j=0; j<3; j++)
			cin>>house[i][j];
	}

	for (int i=0; i<3; i++) {
		dp[0][i] = house[0][i];
	}

	for (int i=1; i<N; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
	}

	int num = min(dp[N-1][0], dp[N-1][1]);
	if (num > dp[N-1][2])
		num = dp[N-1][2];
	cout<<num<<endl;

	return 0;
}