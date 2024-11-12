#include <iostream>

using namespace std;

int T,N;

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N;

		int sum=0;
		for (int i=1; i<N; i++) {
			if (N % i == 0) {
				sum += i;
			}
		}
		if (sum == N) {
			cout << "Perfect\n";
		}
		else if (sum < N) {
			cout << "Deficient\n";
		}
		else if (sum > N) {
			cout << "Abundant\n";
		}
	}

	return 0;
}