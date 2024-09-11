#include <iostream>

using namespace std;

int main(void) {

	string str;
	cin >> str;

	int ans=0;
	for (int i=0; i<str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}