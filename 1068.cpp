#include <iostream>
#include <vector>

using namespace std;

vector<int> v[51];
bool check[51];

void	dfs(int n) {
	if (v[n].size() == 0) {
		v[n].push_back(-1);
		return ;
	}

	for (int i=0; i<v[n].size(); i++) {
		dfs(v[n][i]);
	}
}

int main(void) {
	int N;
	cin >> N;

	int num;
	for (int i=0; i<N; i++) {
		cin >> num;
		if (num == -1)
			continue;
		v[num].push_back(i);
	}

	int del;
	cin >> del;
	dfs(del);

	int cnt=0;
	for (int i=0; i<N; i++) {
		if (v[i].size() == 0 || (v[i].size() == 1 && v[i][0] == del)) {	
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}