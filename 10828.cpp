#include "stdc++.h"

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> st;
	for (int i=0; i<N; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int num;
			cin >> num;
			st.push(num);
		}
		else if (s == "pop") {
			if (st.empty())
				cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (s == "size")
			cout << st.size() << "\n";
		else if (s == "empty")
			cout << (int)st.empty() << "\n";
		else {
			if (st.empty())
				cout << -1 << "\n";
			else
				cout << st.top() << "\n";
		}
	}
}