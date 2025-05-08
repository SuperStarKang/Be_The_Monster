#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string s,ans;
map<char, string> list = {
	{'a', "aespa"},
	{'b', "baekjoon"},
	{'c', "cau"},
	{'d', "debug"},
	{'e', "edge"},
	{'f', "firefox"},
	{'g', "golang"},
	{'h', "haegang"},
	{'i', "iu"},
	{'j', "java"},
	{'k', "kotlin"},
	{'l', "lol"},
	{'m', "mips"},
	{'n', "null"},
	{'o', "os"},
	{'p', "python"},
	{'q', "query"},
	{'r', "roka"},
	{'s', "solvedac"},
	{'t', "tod"},
	{'u', "unix"},
	{'v', "virus"},
	{'w', "whale"},
	{'x', "xcode"},
	{'y', "yahoo"},
	{'z', "zebra"}
};

int main(void) {
	cin >> s;

	int idx=0, size=0;
	while (idx < s.size()) {
		if (list.find(s[idx]) == list.end()) {
			cout << "ERROR!\n";
			return 0;
		}
		string hg = list[s[idx]];
		size = 0;

		while (idx < s.size() && size < hg.size() && hg[size] == s[idx]) {
			idx++;
			size++;
		}
		if (size != hg.size()) {
			cout << "ERROR!\n";
			return 0;
		}
		ans += hg[0];
	}

	cout << "It's HG!\n";
	cout << ans << "\n";
	return 0;
}