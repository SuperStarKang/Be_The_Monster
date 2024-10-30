#include <iostream>

using namespace std;

int main(void) {
	string subject,grade;
	double credit,sum_credit=0,ans=0;

	for (int i=0; i<20; i++) {
		cin >> subject >> credit >> grade;
		if (grade == "A+") {
			ans += 4.5 * credit;
		}
		else if (grade == "A0") {
			ans += 4.0 * credit;
		}
		else if (grade == "B+") {
			ans += 3.5 * credit;
		}
		else if (grade == "B0") {
			ans += 3.0 * credit;
		}
		else if (grade == "C+") {
			ans += 2.5 * credit;
		}
		else if (grade == "C0") {
			ans += 2.0 * credit;
		}
		else if (grade == "D+") {
			ans += 1.5 * credit;
		}
		else if (grade == "D0") {
			ans += 1.0 * credit;
		}
		else if (grade == "F") {
			ans += 0 * credit;
		}
		else if (grade == "P") {
			continue;
		}
		sum_credit += credit;
	}

	cout << ans / sum_credit << '\n';

	return 0;
}
