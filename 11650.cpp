#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> v;

void merge(int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<pair<int,int>> L,R;
	for (int i=0; i<n1; i++) {
		L.push_back(v[left+i]);
	}
	for (int i=0; i<n2; i++) {
		R.push_back(v[mid+1+i]);
	}

	int i=0,j=0;
	int k=left;
	while (i < n1 && j < n2) {
		if (L[i].first < R[j].first) {
			v[k] = L[i];
			k++;
			i++;
		}
		else if (L[i].first == R[j].first) {
			if (L[i].second < R[j].second) {
				v[k] = L[i];
				i++;
			}
			else {
				v[k] = R[j];
				j++;
			}
			k++;
		}
		else {
			v[k] = R[j];
			k++;
			j++;
		}
	}

	while (i < n1) {
		v[k++] = L[i++];
	}
	while (j < n2) { 
		v[k++] = R[j++];
	}
}

void merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left+right)/2;
		merge_sort(left, mid);
		merge_sort(mid+1, right);
		merge(left, mid, right);
	}
}

int main(void) {
	cin >> N;

	int x,y;
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		v.push_back({x,y});
	}

	merge_sort(0,N-1);

	for (int i=0; i<N; i++) {
		cout << v[i].first << ' ' << v[i].second << "\n";
	}
	return 0;
}