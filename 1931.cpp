#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	int N;
	cin>>N;

	vector<pair<int,int>> m;
	int start,end;
	for (int i=0; i<N; i++) {
		cin>>start>>end;
		m.push_back(make_pair(end, start));
	}

	sort(m.begin(), m.end());

	int cnt=1;
	int flag=0;
	start = m.begin()->second;
	end = m.begin()->first;
	for (auto iter=m.begin(); ; cnt++) {
		for (auto idx=iter+1; idx != m.end(); idx++) {
			if (idx->second >= end) {
				start = idx->second;
				iter = idx;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		start = iter->second;
		end = iter->first;
	}
	cout<<cnt<<endl;
	return 0;
}
