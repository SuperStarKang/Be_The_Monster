#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> list;

bool check_prefix(string s1, string s2) {
	size_t i=0;
	while (i < s1.length() && i < s2.length()) {
		if (s1[i] != s2[i]) {
			return false;
		}
		i++;
	}
	return true;
}

int main(void) {
	cin >> N;

	string str;
	for (int i=0; i<N; i++) {
		cin >> str;
		list.push_back(str);
	}

	sort(list.begin(), list.end());
	
	int ans = 1;
	for (int i=1; i<N; i++) {
		ans += 1;
		if (check_prefix(list[i-1], list[i])) {
			ans -= 1;
		}
	}

	cout << ans << '\n';
	return 0;
}