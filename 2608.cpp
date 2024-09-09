#include <iostream>
#include <vector>

using namespace std;

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

#define IV 4
#define IX 9
#define XL 40
#define XC 90
#define CD 400
#define CM 900

string s1,s2;
int sum;
int nums[4];

void add(string s) {
	int i=0;
	while (i < s.length()) {
		if (i < s.length()-1) {
			char tmp[3];
			tmp[0] = s[i];
			tmp[1] = s[i+1];
			tmp[2] = '\0';

			string str(tmp);

			if (str == "IV") {
				sum += IV;
				i += 2;
				continue;
			}
			else if (str == "IX") {
				sum += IX;
				i += 2;
				continue;
			}
			else if (str == "XL") {
				sum += XL;
				i += 2;
				continue;
			}
			else if (str == "XC") {
				sum += XC;
				i += 2;
				continue;
			}
			else if (str == "CD") {
				sum += CD;
				i += 2;
				continue;
			}
			else if (str == "CM") {
				sum += CM;
				i += 2;
				continue;
			}
		}

		if (s[i] == 'I') {
			sum += I;
		}
		else if (s[i] == 'V') {
			sum += V;
		}
		else if (s[i] == 'X') {
			sum += X;
		}
		else if (s[i] == 'L') {
			sum += L;
		}
		else if (s[i] == 'C') {
			sum += C;
		}
		else if (s[i] == 'D') {
			sum += D;
		}
		else if (s[i] == 'M') {
			sum += M;
		}
		i++;
	}
}

int main(void) {
	cin >> s1 >> s2;

	add(s1);
	add(s2);

	cout << sum << '\n';

	vector<string> ans;

	int i=0;
	while (sum > 0) {
		string str = "";
		int n = sum % 10;
		int j=0;

		if (i == 0) {
			if (n == 4) {
				str = "IV";
			}
			else if (n == 9) {
				str = "IX";
			}
			else if (n >= 5) {
				str += "V";
				while (n > 5) {
					str += "I";
					n--;
				}
			}
			else {
				while (n > 0) {
					str += "I";
					n--;
				}
			}
		}
		else if (i == 1) {
			if (n == 4) {
				str = "XL";
			}
			else if (n == 9) {
				str = "XC";
			}
			else if (n >= 5) {
				str += "L";
				while (n > 5) {
					str += "X";
					n--;
				}
			}
			else {
				while (n > 0) {
					str += "X";
					n--;
				}
			}
		}
		else if (i == 2) {
			if (n == 4) {
				str = "CD";
			}
			else if (n == 9) {
				str = "CM";
			}
			else if (n >= 5) {
				str += "D";
				while (n > 5) {
					str += "C";
					n--;
				}
			}
			else {
				while (n > 0) {
					str += "C";
					n--;
				}
			}
		}
		else if (i == 3) {
			while (n > 0) {
				str += "M";
				n--;
			}
		}

		ans.push_back(str);

		sum /= 10;
		i++;
	}

	for (int i=ans.size()-1; i>=0; i--) {
		cout << ans[i];
	}
	cout << '\n';
	
	return 0;
}