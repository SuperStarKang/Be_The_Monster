#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int T;
int primes[400000];

bool is_prime(int n) {
	if (n == 0 || n == 1) {
		return false;
	}
	for (int i=2; i<=sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void make_primes() {
	for (int i=2; i<400000; i++) {
		if (is_prime(i)) {
			for (int j=i+i; j<400000; j+=i) {
				primes[j] = 1;
			}
		}
	}
}

int main(void) {
	cin >> T;

	make_primes();
	primes[0] = 1;
	primes[1] = 1;

	int n;
	while (T--) {
		cin >> n;

		int cnt=0;
		while (true) {
			if (primes[cnt] == 0) {
				n--;
			}
			if (n == 0) {
				break;
			}
			cnt++;
		}

		int i=1;
		while (true) {
			if (primes[i] == 0) {
				cnt--;
			}
			if (cnt == 0) {
				break;
			}
			i++;
		}
		cout << i << '\n';
	}


	return 0;
}