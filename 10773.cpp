#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int num;
	vector<int> v;
	for (int i=0; i<n; i++) {
		cin >> num;
		if (num == 0) {
			v.pop_back();
		}
		else {
			v.push_back(num);
		}
	}

	int sum = 0;
	for (size_t i = 0; i<v.size(); i++) {
		sum += v[i];
	}

	cout << sum << std::endl;
	return 0;
}