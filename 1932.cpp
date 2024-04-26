#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[501];
int n;

int main(void) {
	cin >> n;

	int num;
	for (int i=0; i<n; i++) {
		for (int j=0; j<i+1; j++) {
			cin >> num;
			v[i].push_back(num);
		}
	}
	for (int i=1; i<n; i++) {
		v[i][0] += v[i-1][0];
		for (int j=1; j<i; j++) {
			v[i][j] += max(v[i-1][j], v[i-1][j-1]);
		}
		v[i][i] += v[i-1][i-1];
	}

	int max=0;
	for (int i=0; i<n; i++) {
		if (v[n-1][i] > max)
			max = v[n-1][i];
	}
	cout << max << endl;
	return 0;
}
