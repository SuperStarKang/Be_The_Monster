#include <iostream>

using namespace std;

long long dp[10001];

int main(void) {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	for (int i=3; i<=n; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % 10007;
	}
	cout << dp[n] << endl;
	return 0;
}