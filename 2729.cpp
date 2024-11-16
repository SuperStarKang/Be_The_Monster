#include <iostream>
#include <cmath>

using namespace std;

int N;

string addBinary(string a, string b) {
    string result = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }
    
    return result;
}

int main(void) {
	cin >> N;

	while (N--) {
		string n1, n2;
		cin >> n1 >> n2;
		
		string result = addBinary(n1, n2);
		bool flag = false;
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == '1') {
				flag = true;
			}
			if (flag) {
				cout << result[i];
			}
		}
		if (!flag) {
			cout << '0';
		}
		cout << '\n';
	}
	return 0;
}