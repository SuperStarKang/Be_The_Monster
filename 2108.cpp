#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[500001];
int countin[8002];
int modes[4001];

void merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void   quick_sort(int start, int end) {
	if (start >= end)
		return ;

	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right) {
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		while (right > start && arr[right] >= arr[pivot])
			right--;
		if (left > right)
			swap(arr[pivot], arr[right]);
		else
			swap(arr[left], arr[right]);
	}
	quick_sort(start, right-1);
	quick_sort(right+1, end);
}

int main(void) {
	int N;
	cin>>N;

	double total=0;
	int max=-4001,min=4001;
	for (int i=0; i<N; i++) {
		cin>>arr[i];
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
		countin[arr[i]+4000]++;
		total += arr[i];
	}

	mergeSort(0,N-1);
	// quick_sort(0, N-1);

	int mode=0;
	for (int i=0; i<=8000; i++) {
		if (countin[i] > mode)
			mode = countin[i];
	}

	int idx=0;
	for (int num=0; num<=8000; num++) {
		if (countin[num] == mode) {
			modes[idx] = num-4000;
			idx++;
		}
	}

	if (round(total/N) == 0)
		cout<<0<<endl;
	else
		cout<<round(total/N)<<endl;

	cout<<arr[N/2]<<endl;

	if (idx == 1) {
		cout<<modes[0]<<endl;
	}
	else {
		cout<<modes[1]<<endl;
	}

	cout<<max-min<<endl;
	return 0;
}
