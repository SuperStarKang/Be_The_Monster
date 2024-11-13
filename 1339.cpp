#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<string> strs;
int alphabet[26];
bool check[26];

int main(void) {
	cin >> N;

	string str;
	for (int i=0; i<N; i++) {
		cin >> str;
		strs.push_back(str);
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<strs[i].size(); j++) {
			alphabet[strs[i][j] - 'A'] += pow(10, strs[i].size() - j - 1);
		}
	}

	int sum=0;
	int n=9;
	for (int i=0; i<26; i++) {
		bool flag = false;
		int high = 0;
		int high_idx = 0;
		for (int j=0; j<26; j++) {
			if (!check[j] && alphabet[j] > 0 && alphabet[j] > high) {
				high = alphabet[j];
				high_idx = j;
				flag = true;
			}
		}
		check[high_idx] = true;
		if (flag) {
			sum += high * n;
		}
		n--;
	}

	cout << sum << '\n';

	return 0;
}