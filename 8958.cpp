#include <iostream>
#include <vector>

using namespace std;

int T;
string str;

int main(void) {
	cin >> T;

	while (T--) {
		cin >> str;

		int result=0,flag=1;
		for (int i=0; i<str.size(); i++) {
			if (str[i] == 'O') {
				result += flag;
				flag++;
			}
			else {
				flag = 1;
			}
		}
		cout << result << '\n';
	}

	return 0;
}