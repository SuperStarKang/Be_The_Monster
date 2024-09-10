#include <iostream>

using namespace std;

int main(void) {
	int K;
	cin >> K;

	string str;
	cin >> str;

	for (int i=0; i<str.length(); i++) {
		if (i % K == 0 ) {
			cout << str[i];
		}
	}
	cout << '\n';


	return 0;
}