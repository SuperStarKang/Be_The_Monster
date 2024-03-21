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
	int j=1;
	while (j<N) {
		int k;
		int same=0;
		int small=0;
		for (k=j-1; k>=0; k--) {
			if (arr[k] == arr[j]) {
				if (same < dp[k])
					same = dp[k];
			}
			if (arr[k] < arr[j]) {
				if (small < dp[k])
					small = dp[k];
			}
		}
		if (same > small) {
			dp[j] = same;
		}
		else {
			dp[j] = small+1;
		}
		j++;
	}

	int max=0;
	for (int i=0; i<N; i++) {
		if (max < dp[i])
			max = dp[i];
	}
	cout<<max<<endl;

	return 0;
}