#include <iostream>

using namespace std;

bool is_prime(int n) {
	for (int i=2; i*i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(void) {
	int N,K;
	cin>>N>>K;

	int list[N+1];
	int ans[N+1];
	for (int i=0; i<=N; i++) {
		list[i] = i;
		ans[i] = 0;
	}

	int idx=0;
	for (int i=2; i<=N; i++) {
		for (int j=i; j<=N; j += i) {
			if (list[j] == 0)
				continue;
			ans[idx++] = list[j];
			list[j] = 0;
		}
	}
	cout<<ans[K-1]<<endl;
	return 0;
}