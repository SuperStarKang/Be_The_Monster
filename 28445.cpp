#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

int main(void) {
	string color[4];

	int flag = 0;
	for (int i=0; i<4; i++) {
		cin >> color[i];
		for (int j=0; j<i; j++) {
			if (color[i] == color[j])
				flag = 1;
		}
		if (!flag)
			v.push_back(color[i]);
		else
			flag = 0;
	}

	sort(v.begin(), v.end());

	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v.size(); j++) {
			cout << v[i] << ' ' << v[j] << endl;
		}
	}
	
	return 0;
}