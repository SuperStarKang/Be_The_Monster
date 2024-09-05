#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int N;
bool alphabet[27];
bool flag;
vector<pair<string, int>> options;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	cin.ignore();
	string str;
	for (int i=0; i<N; i++) {
		getline(cin, str);
		options.push_back({str, -2});
	}

	for (int i=0; i<N; i++) {
		flag = false;
		for (int j=0; j<options[i].first.length(); j++) {
			if (j == 0 || (j > 0 && options[i].first[j-1] == ' ')) {
				if (isupper(options[i].first[j])) {
					if (!alphabet[options[i].first[j] - 'A']) {
						alphabet[options[i].first[j] - 'A'] = true;
						flag = true;
						options[i].second = j;
						break;
					}
				}
				else if (islower(options[i].first[j])) {
					if (!alphabet[options[i].first[j] - 'a']) {
						alphabet[options[i].first[j] - 'a'] = true;
						flag = true;
						options[i].second = j;
						break;
					}
				}
			}
		}

		if (!flag) {
			int j=0;
			while (j < options[i].first.length()) {
				if (isupper(options[i].first[j])) {
					if (!alphabet[options[i].first[j] - 'A']) {
						alphabet[options[i].first[j] - 'A'] = true;
						options[i].second = j;
						break;
					}
				}
				else if (islower(options[i].first[j])) {
					if (!alphabet[options[i].first[j] - 'a']) {
						alphabet[options[i].first[j] - 'a'] = true;
						options[i].second = j;
						break;
					}
				}
				j++;
			}
		}
	}

	for (int i=0; i<N; i++) {
		int j=0;
		while (j < options[i].first.length()) {
			if (j == options[i].second) {
				cout << '[';
			}
			else if (j - 1 == options[i].second) {
				cout << ']';
			}
			cout << options[i].first[j];
			j++;
		}
		if (options[i].second == j - 1) {
			cout << ']';
		}
		cout << '\n';
	}

	return 0;
}