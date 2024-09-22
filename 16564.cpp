#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N,K,T;
vector<long long> levels;

int main(void) {
	cin >> N >> K;

	long long level;
	for (int i=0; i<N; i++) {
		cin >> level;
		levels.push_back(level);
	}

	sort(levels.begin(), levels.end());

	long long left=levels[0],right=2000000000,mid=0;
	long long sum=0;
	while (left <= right) {
		mid = (left+right)/2;
		sum = 0;

		for (int i=0; i<N; i++) {
			if (levels[i] < mid) {
				sum += mid - levels[i];
			}
			else {
				break;
			}	
		}

		if (sum > K) {
			right = mid - 1;
		}
		else {
			T = mid;
			left = mid + 1;
		}
	}

	cout << T << '\n';

	return 0;
}