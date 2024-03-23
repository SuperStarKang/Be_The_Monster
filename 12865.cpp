#include <iostream>
#include <algorithm>

using namespace std;

int info[100001][2];
int dp[1001][100001];

int main(void) {
	int N,K;
	cin>>N>>K;

	for (int i=1; i<=N; i++) {
		for (int j=0; j<2; j++)
			cin>>info[i][j];
	}

	for (int j=1; j<=K; j++) {
		for (int i=1; i<=N; i++) {
			if (j - info[i][0] < 0) {
				dp[i][j] = dp[i-1][j];
			}
			else
				dp[i][j] = max(dp[i-1][j - info[i][0]] + info[i][1], dp[i-1][j]);
		}
	}

	for (int i=0; i<=N; i++) {
		for (int j=0; j<=K; j++)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}

	cout<<dp[N][K]<<endl;
	return 0;
}
