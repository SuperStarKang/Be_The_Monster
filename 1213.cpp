#include <iostream>
#include <vector>

using namespace std;

int alpha[30];

int main(void) {
	string str;
	cin >> str;

	int len = str.length();

	for (int i=0; i<len; i++) {
		int idx = str[i] - 'A';
		alpha[idx]++;
	}

	int odd_alpha=0;
	int odd_cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 != 0) {
			odd_alpha = i;
			odd_cnt++;
		}
	}
	if (odd_cnt > 1) {
		cout << "I'm Sorry Hansoo" << endl;
		return 0;
	}

	string result = "";
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > 0) {
			char ch = i + 'A';
			for (int cnt=0; cnt < alpha[i]/2; cnt++) {
				result += ch;
			}
		}
	}

	if (len % 2 != 0) {
		result += odd_alpha + 'A';
	}

	for (int i=25; i>=0; i--) {
		if (alpha[i] > 0) {
			char ch = i + 'A';
			for (int cnt=0; cnt < alpha[i]/2; cnt++) {
				result += ch;
			}
		}
	}

	cout << result << '\n';
	return 0;
}
