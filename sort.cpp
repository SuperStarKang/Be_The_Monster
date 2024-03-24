#include <iostream>

using namespace std;

int n = 10;
int arr[10] = {3, 2, 9, 8, 1, 7, 4, 6, 5, 0};
int sorted[10];

void   quick_sort(int *arr, int start, int end) {
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
	quick_sort(arr, start, right-1);
	quick_sort(arr, right+1, end);
}

void	merge(int left, int mid, int right){
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	if (i > mid) {
		for (l=j; l<=right; l++)
			sorted[k++] = arr[l];
	}
	else {
		for(l=i; l<=mid; l++)
			sorted[k++] = arr[l];
	}

	for (l=left; l<=right; l++) {
		arr[l] = sorted[l];
	}
}

void	merge_sort(int left, int right){
	int mid;

	if (left<right){
		mid = (left+right)/2;
		merge_sort(left, mid);
		merge_sort(mid+1, right);
		merge(left, mid, right);
	}
}

void   insertion_sort() {
   for (int i=1; i<n; i++) {
      for (int j=i; j>0; j--) {
         if (arr[j] < arr[j-1])
            swap(arr[j], arr[j-1]);
         else
            break;
      }
   }

   for (int i=0; i<n; i++)
      cout<<arr[i]<<' ';
   cout<<endl;
}

void   selection_sort() {
   for (int i=0; i<n; i++) {
      int min = i;
      for (int j=i+1; j<n; j++) {
         if (arr[min] > arr[j])
            min = j;
      }
      swap(arr[i], arr[min]);
   }

   for (int i=0; i<n; i++)
      cout<<arr[i]<<' ';
   cout<<endl;
}

int main(void) {
//    for (int i=0; i<n; i++)
//       cout<<arr[i]<<' ';
//    cout<<endl;

   // selection_sort();
   // insertion_sort();
   merge_sort(0,n-1);
//    quick_sort(arr, 0, n-1);

//    for (int i=0; i<n; i++)
//       cout<<arr[i]<<' ';
//    cout<<endl;

   return 0;
}