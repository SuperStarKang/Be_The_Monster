#include <iostream>

using namespace std;

string str;

int main(void) {
	cin >> str;

	long long sum=0;
	for (int i=0; i<str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			sum += str[i] - 'a' + 1;
		} else {
			sum += str[i] - 'A' + 27;
		}
	}

	for (long long i=2; i*i<=sum; i++) {
		if (sum % i == 0) {
			cout << "It is not a prime word.\n";
			return 0;
		}
	}
	cout << "It is a prime word.\n";

	return 0;
}