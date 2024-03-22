#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main(void) {
	int N;
	cin>>N;

	for (int i=0; i<N; i++)
		cin>>arr[i];
	
	dp[0] = 1;
	for (int i=0; i<N; i++) {
		int same=0;
		int big=0;
		for (int j=0; j<i; j++) {
			if (arr[j] == arr[i] && same < dp[j]) {
				same = dp[j];
			}
			else if (arr[j] > arr[i] && big < dp[j]) {
				big = dp[j];
			}
		}
		if (same > big) {
			dp[i] = same;
		}
		else {
			dp[i] = big+1;
		}
	}

	int max=0;
	for (int i=0; i<N; i++) {
		if (max < dp[i])
			max = dp[i];
	}
	cout<<max<<endl;
	return 0;
}