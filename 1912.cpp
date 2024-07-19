#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> list;
int dp[100001];
int result;

int main(void) {
	cin >> n;
	int num;
	for (int i=0; i<n; i++) {
		cin >> num;
		list.push_back(num);
	}

	dp[0] = list[0];
	result = list[0];
	for (int i=1; i<n; i++) {
		if (dp[i-1] + list[i] < 0) {
			if (dp[i-1] < 0) {
				dp[i] = max(dp[i-1], list[i]);
			}
			else {
				dp[i] = 0;
			}
		}
		else {
			dp[i] = dp[i-1] + list[i];
		}
		result = max(result, dp[i]);
	}
	cout << result << '\n';
	return 0;
}