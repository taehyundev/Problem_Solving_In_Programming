#include <iostream>
#define max 9
using namespace std;

int sorted[8];
 
void mergeSort(int a[], int m, int middle, int n) {
	int i = m; //i----mid(middle) / mid+1(j)---n
	int j = middle+1;
	int k = m; //sorted 배열의 인덱스를 증가시켜 참조하기위한 변수 k == i 와 초기값이 같다

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
	if (i > middle) { // 같을 수가 없다. 그래서 i가 더크면 i가 먼저 끝나서 끝난거
		for (int t = j; t <= n; t++) { // 이후 k의 다음지점부터 쭉 연결시켜준다.
			sorted[k] = a[t];
			k++;
		}
	}
	else { // j가 먼저끝났을때
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	// 정렬된 배열을 삽입 
	for (int t = m; t <= n; t++) { //기존의 배열에 담아준다.
		a[t] = sorted[t];
	}
}

void partition(int* a, int n, int m) { // 분할와 정복?  n 은 시작 m 끝


	if (m > n) { // 당연한 소리 이 조건에 맞지 못하면 배열이 끝나거나 비였나? 뭐 그런 이상한 느낌인거죠

		int mid = (n + m) / 2;

		partition(a, n, mid);
		partition(a, mid+1, m);
		
		mergeSort(a,n,mid, m);
	}
}



int main() {
	int array[max] = { 9,8,6,7,5,4,3,2,1 };
	partition(array, 0,max-1); //끝 index 끝지점이 max -1 이기 떄문에
	for (int i = 0; i < max; i++) {
		cout << array[i] << " ";
	}
}
