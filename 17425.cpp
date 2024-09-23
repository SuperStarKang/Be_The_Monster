#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N,T;
long long nums[1000001];

void make_arr() {
	for (long long i=1; i<=1000000; i++) {
		for (long long j=i; j<=1000000; j+=i) {
			nums[j] += i;
		}
		nums[i] += nums[i-1];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	make_arr();
	while (T--) {
		cin >> N;

		cout << nums[N] << '\n';
	}

	return 0;
}