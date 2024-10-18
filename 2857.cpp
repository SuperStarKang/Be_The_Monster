#include <iostream>
#include <vector>

using namespace std;

vector<int> agent;

int main(void) {
	string name;
	for (int i=0; i<5; i++) {
		cin >> name;
		if (name.find("FBI") != string::npos) {
			agent.push_back(i);
		}
	}

	if (agent.size() == 0 ) {
		cout << "HE GOT AWAY!\n";
	}
	else {
		for (int i=0; i<agent.size(); i++) {
			cout << agent[i] + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}