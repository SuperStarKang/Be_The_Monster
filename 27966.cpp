#include <iostream>

using namespace std;

long long sum[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long N;
	cin >> N;

	sum[3] = 1;
	for (long long i=4; i<=N; i++) {
		sum[i] = sum[i-1] + i-2;
	}

	cout << N-1 + 2*sum[N] << "\n";
	for (int i=2; i<=N; i++) {
		cout << 1 << ' ' << i << "\n";
	}

	return 0;
}
