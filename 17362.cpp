#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if (n <= 5) {
		cout << n << '\n';
	}
	else {
		n %= 8;
		if (n == 0) {
			cout << 2 << '\n';
		}
		else if (n <= 5) {
			cout << n << '\n';
		}
		else if (n == 7) {
			cout << 3 << '\n';
		}
		else if (n == 6) {
			cout << 4 << '\n';
		}
	}

	return 0;
}