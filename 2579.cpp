#include <iostream>
#include <algorithm>

using namespace std;

int stair[301];
int dp[301];

int main(void) {
	int N;
	cin>>N;

	for (int i=0; i<N; i++)
		cin>>stair[i];
	
	int i=N-1;
	int check=0;
	while (i > 0) {
		if (max(stair[i], stair[i-1]) == stair[i]) {
			dp[i-1] += stair[i] + dp[i];
			check++;
			i--;
		}
		else {
			dp[i-2] += stair[i-1] + dp[i];
			i -= 2;
		}
	}
	for (int i=0; i<N; i++)
		cout<<dp[i]<<' ';
	cout<<endl;

	return 0;
}