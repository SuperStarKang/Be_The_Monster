#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check[100001];
vector<int> v[100001];
int ans[100001];

void	make_tree(int n) {
	check[n] = true;

	for (int i=0; i<v[n].size(); i++) {
		int next = v[n][i];
		if (!check[next]) {
			ans[next] = n;
			make_tree(next);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int n1,n2;
	for (int i=0; i<N-1; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	make_tree(1);

	for (int i=2; i<=N; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}
