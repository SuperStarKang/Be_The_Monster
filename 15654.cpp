#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> v;
int arr[10];
bool visited[10];

void sol(int depth) {
	if (depth == M) {
		for (int i=0; i<M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i=0; i<N; i++) {
		if (!visited[i]) {
			arr[depth] = v[i];
			visited[i] = true;
			sol(depth+1);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> N >> M;

	int n;
	for (int i=0; i<N; i++) {
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());

	sol(0);

	return 0;
}