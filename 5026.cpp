#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main(void) {
	cin >> N;

	while (N--) {
		string str;
		cin >> str;

		if (str == "P=NP") {
			cout << "skipped\n";
		}
		else {
			int n1 = stoi(str.substr(0, str.find('+')));
			int n2 = stoi(str.substr(str.find('+')));
			cout << n1+n2 << '\n';
		}
	}

	return 0;
}