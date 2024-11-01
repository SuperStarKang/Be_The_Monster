#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main(void) {
	cin >> N;

	while (N > 0) {
		arr.push_back(N % 10);
		N /= 10;
	}

	sort(arr.begin(), arr.end());

	for (int i=arr.size()-1; i>=0; i--) {
		cout << arr[i];
	}
	cout << '\n';
	return 0;
}