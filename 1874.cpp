#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
bool flag=false;
vector<int> v;
stack<int> s;
vector<char> vc;

int main(void) {
	cin >> n;
	for (int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int i=0;
	int k=1;
	while (i < n) {
		if (s.empty()) {
			s.push(k);
			vc.push_back('+');
			k++;
		}

		if (s.top() == v[i]) {
			s.pop();
			vc.push_back('-');
			i++;
		}
		else if (s.top() < v[i]) {
			s.push(k);
			vc.push_back('+');
			k++;
		}
		else if (s.top() > v[i]) {
			flag = true;
			break;
		}
	}

	if (flag) {
		cout << "NO\n";
	}
	else {
		for (int i=0; i<vc.size(); i++) {
			cout << vc[i] << '\n';
		}
	}
	return 0;
}