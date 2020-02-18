/*

< Quick Sort >

1. 파티션 분리 LeftNode(small) <--------------->RightNode(Big) 

2. LeftNode 를 Quick Sort 정렬에 넣는다.

3. RightNode를 Quick Sort 정렬에 넣는다.

*/
#include <iostream>
using namespace std;
void show(int * data) {
	int i;
	for (i = 0; i < 10; i++)
		cout << data[i] << " " << endl;
}

void quickSort(int * data, int start, int end) {
	//기준을 정한다.(첫번째가 기준)
	int Pivot = start;
	
	//재귀 함수가 나올만한 조건문이 필요함
	if (end <= start) {
		return;
	}

	//기준을 제외한 형태로 반복문에서 사용될 start와 end를 재 정의 한다.
	int i = start + 1, j = end;
	int temp;

	while (i<= j) { //안 엇갈려야 한다.
		//L -> R 방향으로 가면서 기준점보다 큰 수를 찾는 반복문
		while (data[i] <= data[Pivot] && i <=end) { //끝까지가면 안됨
			i++;
		}

		//R -> L 방향으로 가면서 기준점보다 작은 수를 찾는 반복문
		while (data[Pivot] <= data[j] && start < j) { // j가 -1이 될 수 도 있음
			j--;
		}

		if (i > j) { //엇갈렸다 Pivot랑 작은수랑 변경
			temp = data[Pivot];
			data[Pivot] = data[j];
			data[j] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}

	}

	//Left Node를 재귀함수로 돌림
	quickSort(data, start, j-1);
	//Right Node를 재귀함수로 돌림
	quickSort(data, j+1, end);
}

int main() {
	int data[] = { 1,5,2,8,7,3,6,4,10,9 };
	int max = 10;
	quickSort(data, 0, max-1); // 인자값 : (data, start, end)
	show(data);
}
