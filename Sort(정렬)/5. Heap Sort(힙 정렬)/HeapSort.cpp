#include <iostream>
using namespace std;
#define max 9

int heap[9] = { 8,7,6,5,4,3,2,1,9 };

int main() {
	//root를 찾는 과정
	//최대 힙 구조 
	for (int i = 1; i < max; i++) { // root를 제외하고 반복 
		int child = i;
		do {
			int root = (child - 1) / 2; //첫 root는 0 

			if (heap[root] < heap[child]) {
				int temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}
			child = root;
		} while (child != 0); //자식이 root가 안될 때 까지 
	}

	for (int i = 0; i < max; i++) {
		cout << heap[i] << " ";
	}
	cout << endl;
	// 9 8 6 7 4 3 2 1 5

	//index 0번째의 root를 기준으로 
	for (int i = max - 1; i >= 0; i--) {
		int temp = heap[0];
		cout << heap[0] << endl; //정렬을 위해서 root는 항상 크기 때문에 root를 뒷쪽으로 옮기고 옮긴걸 제외하고 root를 찾고 그 root를 옮기는 형태
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0; //root의 시작 
		int child = 1; //자식의 시작 
		do {
			child = 2 * root + 1; //자식 찾음 i보다 작아야함

			if (child < i - 1 && heap[child] < heap[child + 1]) { //자식중에 큰 자식을 봄 자식 ++ vs 자식
				child++;
			}

			//본격적인 자리이동
			if (child < i && heap[root] < heap[child]) {
				temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}
			root = child;
		} while (child < i);
	}

	for (int i = 0; i < max; i++) {
		cout << heap[i] << " ";
	}

}
/*
선별 후 : 9 8 6 7 4 3 2 1 5
1 : 5 8 6 7 4 3 2 1 9  9가 뒤로옴
root를 다시 찾음
2 : 1 7 6 5 4 3 2 8 9 8이 9앞으로옴(8이 root자리로 가고)
root를 다시 찾음
3 : 2 5 6 1 4 3 7 8 9 7이 8앞으로 옴
root를 다시 찾음
4 : 2 5 3 1 4 6 7 8 9
root를 다시 찾음
5 : 2 4 3 1 5 6 7 8 9
root를 다시 찾음
6 : 1 2 3 4 5 6 7 8 9
root를 다시 찾음
7 : 1 2 3 4 5 6 7 8 9
root를 다시 찾음
8 : 1 2 3 4 5 6 7 8 9
root를 다시 찾음
9 : 1 2 3 4 5 6 7 8 9
끝

*/