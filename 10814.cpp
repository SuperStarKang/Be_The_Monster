#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, string>> v;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back(make_pair(age, name));
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}