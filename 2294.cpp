#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int n,k;
int dp[10001];

int main(void) {
	cin >> n >> k;

	int num;
	for (int i=0; i<n; i++) {
		cin >> num;
		v.push_back(num);
	}
 
	sort(v.begin(), v.end());

	for (int i=0; i<=k; i++) {
		dp[i] = 1000000;
	}

	dp[0] = 0;
	for (int i=0; i<n; i++) {
		for (int j=v[i]; j<=k; j++) {
			dp[j] = min(dp[j], dp[j-v[i]] + 1);
		}
	}

	if (dp[k] == 1000000) {
		cout << -1 << '\n';
	}
	else {
		cout << dp[k] << '\n';
	}

	return 0;
}