#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<string> list;

int main(void) {
	cin >> N;
	string str;
	for (int i=0; i<N; i++) {
		cin >> str;
		list.push_back(str);
	}

	int len = str.length();

	for (int i=0; i<N; i++) {
		for (int j = 0; j < len; j++) {
			if (str[j] != list[i][j]) {
				str[j] = '?';
			}
		}
	}

	cout << str << endl;
	return 0;
}