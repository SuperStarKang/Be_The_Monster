#include <iostream>
#include <cmath>

using namespace std;

int solutions[100001];
int result[2];

int main(void) {
	int N;
	cin>>N;

	for (int i=0; i<N; i++)
		cin>>solutions[i];
	
	int min = 2147483647;
	int l=0,r=N-1;

	while (l < r) {
		if (min > abs(solutions[l]+solutions[r])) {
			min = abs(solutions[l]+solutions[r]);
			result[0] = solutions[l];
			result[1] = solutions[r];
		}

		if (solutions[l]+solutions[r] < 0)
			l++;
		else
			r--;
	}
	cout<<result[0]<<' '<<result[1]<<endl;
	return 0;
}
