#include <iostream>

using namespace std;

int N, ans;
int c[101], k[101];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> c[i] >> k[i];
	}

	for (int i = 0; i < N; i++) {
		ans += c[i] * k[i];
	}

	cout << ans << '\n';
	return 0;
}