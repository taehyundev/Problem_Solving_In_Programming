#include <iostream>
#define max 9
using namespace std;

int sorted[8];
 
void mergeSort(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	// 작은 순서대로 배열에 삽입 
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	// 남은 데이터도 삽입 
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	// 정렬된 배열을 삽입 
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void partition(int* a, int n, int m) {

	if (m > n) {
		int mid = (n + m) / 2;
		partition(a, n, mid);
		partition(a, mid+1, m);
		mergeSort(a,n,mid, m);
	}
}

int main() {
	int array[max] = { 9,8,6,7,5,4,3,2,1 };
	partition(array, 0,max-1);
	for (int i = 0; i < max; i++) {
		cout << array[i] <<" ";
	}
}
