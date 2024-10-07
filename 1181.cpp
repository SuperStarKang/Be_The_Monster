#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> v;

int compare(string s1, string s2) {
	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	else {
		return s1.length() < s2.length();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	string str;
	for (int i=0; i<N; i++) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), compare);

	for (int i=0; i<v.size(); i++) {
		if (i > 0 && v[i] == v[i-1]) {
			continue;
		}
		cout << v[i] << '\n';
	}

	return 0;
}