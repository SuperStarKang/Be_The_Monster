#include <iostream>

using namespace std;

int N,ans;
string want;

int main(void) {
	cin >> want >> N;

	string str;
	while (N--) {
		cin >> str;

		for (int i=0; i<want.size(); i++) {
			str += str[i];
		}

		for (int i=0; i<str.size()-want.size(); i++) {
			bool flag = false;
			if (str[i] == want[0]) {
				int k=i;
				flag = true;
				for (int j=0; j<want.size() && k<str.size(); j++, k++) {
					if (str[k] != want[j]) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				ans++;
				break;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}