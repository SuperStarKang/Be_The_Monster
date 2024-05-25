#include <iostream>

using namespace std;

int N,M,tree_max;
int tree[1000001];

int main(void) {
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> tree[i];
		if (tree_max < tree[i]) {
			tree_max = tree[i];
		}
	}

	int left=0,right=tree_max;
	long long sum=0;
	while (left <= right) {
		int mid = (left+right)/2;
		sum = 0;
		
		for (int i=0; i<N; i++) {
			if (tree[i] - mid > 0)
				sum += tree[i] - mid;
		}

		if (sum < M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left-1 << '\n';
	return 0;
}