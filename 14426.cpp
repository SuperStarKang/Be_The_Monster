#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<string> list;

int main(void) {
	cin >> N >> M;

	string str;
	for (int i=0; i<N; i++) {
		cin >> str;
		list.push_back(str);
	}

	sort(list.begin(), list.end());

	int ans=0;
	for (int i=0; i<M; i++) {
		cin >> str;

		int left=0;
		int right=N-1;

		while (left <= right) {
			int mid = (left+right) / 2;
			if (str < list[mid]) {
				right = mid - 1;
			}
			else if (str > list[mid]) {
				left = mid + 1;
			}

			if (list[mid].substr(0, str.length()) == str) {
				ans++;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}