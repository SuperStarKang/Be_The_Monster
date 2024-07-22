#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> coins;
int dp[10001];

int main(void) {
	cin >> n >> k;

	int coin;
	for (int i=0; i<n; i++) {
		cin >> coin;
		coins.push_back(coin);
	}

	dp[0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=coins[i]; j<=k; j++) {
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}
	cout << dp[k] << '\n';
	return 0;
}