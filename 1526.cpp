#include <iostream>

using namespace std;

int N;

int main(void) {
	cin >> N;

	bool flag = true;
	for (int i=N; i>=4; i--) {
		string num = to_string(i);
		flag = true;

		for (int j=0; j<num.size(); j++) {
			if (num[j] != '4' && num[j] != '7') {
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << num << '\n';
			break;
		}
	}

	return 0;
}