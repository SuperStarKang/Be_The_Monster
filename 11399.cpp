#include <iostream>

using namespace std;

int compare(const void *a, const void *b) {
	const int *x = (int *)a;
	const int *y = (int *)b;

	if (*x > *y) {
		return 1;
	}
	else if (*x < *y)
		return -1;
	
	return 0;
}

int main(void) {
	int N;
	cin>>N;

	int P[N];
	for (int i=0; i<N; i++) {
		cin>>P[i];
	}
	qsort(P,N,sizeof(int),compare);

	int total=0;
	for (int i=0; i<N; i++) {
		int time=0;
		for (int j=0; j<N-i; j++) {
			time += P[j];
		}
		total += time;
	}
	cout<<total<<endl;
	return 0;
}