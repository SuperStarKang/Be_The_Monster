#include <iostream>
#include <cmath>

using namespace std;

int T;

bool is_prime(int n) {
	for (int i=2; i<=sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main(void) {
	cin >> T;

	int k;
	while (T--) {
		cin >> k;

		if (is_prime(k)) {
			cout << 0 << '\n';
		}
		else {
			int low,high;
			bool f1=false,f2=false;
			for (int i=1; i<=1299709;i++) {
				int n1=k+i;
				int n2=k-i;
				if (!f1 && is_prime(n1)) {
					high = n1;
					f1 = true;
				}
				if (!f2 && is_prime(n2)) {
					low = n2;
					f2 = true;
				}

				if (f1 && f2) {
					break;
				}
			}
			cout << high - low << '\n';
		}
	}

	return 0;
}