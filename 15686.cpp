#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct house {
	int x;
	int y;
};

struct chicken {
	int x;
	int y;
	bool visit;
};

vector<house> h;
vector<chicken> ch;

int result=2147483647;

void	cal_distance() {
	int total=0;
	for (int i=0; i<h.size(); i++) {
		int min = 2147483647;
		for (int j=0; j<ch.size(); j++) {
			if (ch[j].visit == true) {
				int dis = abs(h[i].x - ch[j].x) + abs(h[i].y - ch[j].y);
				if (min > dis)
					min = dis;
			}
		}
		total += min;
	}
	if (result > total)
		result = total;
}

void	combination(int M, int depth, int idx) {
	if (depth == M) {
		cal_distance();
		return;
	}

	for (int i=idx; i<ch.size(); i++) {
		if (ch[i].visit == false) {
			ch[i].visit = true;
			combination(M, depth+1, i);
			ch[i].visit = false;
		}
	}
}

int main(void) {
	int N,M;
	cin>>N>>M;

	int info;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin>>info;
			if (info == 1)
				h.push_back({i,j});
			else if (info == 2)
				ch.push_back({i,j,false});
		}
	}

	combination(M,0,0);

	cout<<result<<endl;

	return 0;
}
