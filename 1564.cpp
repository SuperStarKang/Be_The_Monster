#include <iostream>

using namespace std;

long long N;
long long ans[6];

long long factorial() {
	long long k=1;

	for (long long i=2; i<=N; i++) {
		k *= i;
		while (k % 10 == 0) {
			k /= 10;
		}
		k %= 1000000000000;
	}
	k %= 100000;

	return k;
}

int main(void) {
	cin >> N;

	long long fac = factorial();

	int idx=4;
	while (fac > 0) {
		ans[idx] = fac % 10;
		fac /= 10;
		idx--;
	}
	for (int i=0; i<5; i++) {
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}