#include <iostream>
#include <cmath>

using namespace std;

int N;

bool is_palindrome(int n) {
	string str = to_string(n);

	for (int i=0; i<str.length()/2; i++) {
		if (str[i] != str[str.length()-1-i]) {
			return false;
		}
	}
	return true;
}

bool is_prime(int n) {
	for (int j=2; j<=sqrt(n); j++) {
		if (n % j == 0) {
			return false;
		}
	}
	return true;
}

int find_prime() {
	for (int i=N; i<=2147483647; i++) {
		if (i == 1) {
			continue;
		}
		if (is_prime(i)) {
			if (is_palindrome(i)) {
				return i;
			}
		}
	}
	return 0;
}

int main(void) {
	cin >> N;

	cout << find_prime() << '\n';

	return 0;
}