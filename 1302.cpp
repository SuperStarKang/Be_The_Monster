#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int N;
map<string, int> books;

int main(void) {
	cin >> N;
	while (N--) {
		string book;
		cin >> book;
		books[book]++;
	}

	string best;
	int best_count = 0;
	for (auto it = books.begin(); it != books.end(); it++) {
		if (it->second > best_count) {
			best = it->first;
			best_count = it->second;
		}
	}

	cout << best << '\n';

	return 0;
}