#include <iostream>

using namespace std;

int map[501][501];

int main(void) {
	int N,M,B;
	cin>>N>>M>>B;

	int min=300,max=0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin>>map[i][j];
			if (max < map[i][j])
				max = map[i][j];
			if (min > map[i][j])
				min = map[i][j];
		}
	}

	int time=100000000,height=0;
	for (int h=min; h<=max; h++) {
		int total_remove=0,total_add=0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (map[i][j] > h) {
					total_remove += map[i][j] - h;
				}
				else if (map[i][j] < h) {
					total_add += h - map[i][j];
				}
			}
		}
		if (total_add <= total_remove + B) {
			if (time >= total_add + total_remove*2) {
				time = total_add + total_remove*2;
				height = h;
			}
		}
	}
	cout<<time<<' '<<height<<endl;
	return 0;
}
