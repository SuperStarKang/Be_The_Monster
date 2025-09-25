#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> korean;
vector<pair<int, int>> english;
vector<pair<int, int>> math;
vector<pair<int, int>> science;
vector<bool> award;

void print_award(vector<pair<int, int>>& subject) {
	for (int i=0; i<N; i++) {
		if (award[subject[i].first] != true) {
			cout << subject[i].first + 1 << " ";
			award[subject[i].first] = true;
			break;
		}
	}
}

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(void) {
	cin >> N;

	for (int i=0; i<N; i++) {
		int num,k,e,m,s;
		cin >> num;
		cin >> k >> e >> m >> s;
		korean.push_back({num-1, k});
		english.push_back({num-1, e});
		math.push_back({num-1, m});
		science.push_back({num-1, s});
		award.push_back(false);
	}
	sort(korean.begin(), korean.end(), cmp);
	sort(english.begin(), english.end(), cmp);
	sort(math.begin(), math.end(), cmp);
	sort(science.begin(), science.end(), cmp);

	print_award(korean);
	print_award(english);
	print_award(math);
	print_award(science);
	cout << "\n";

	return 0;
}