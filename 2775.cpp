#include <iostream>

using namespace std;

int dp[1000000][15];

int main(void) {
	int T;
	cin>>T;

	dp[0][0] = 1;
	for (int i=1; i<15; i++)
		dp[0][i] += i+1 + dp[0][i-1];

	for (int i=0; i<15; i++) {
		for (int j=0; j<15; j++) {
			for (int l=0; l<=j; l++) {
				dp[i+1][j] += dp[i][l];
			}
		}
	}

	int k,n;
	for (int t=0; t<T; t++) {
		cin>>k>>n;
		cout<<dp[k-1][n-1]<<endl;
	}

	return 0;
}