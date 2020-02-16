#include <iostream>
using namespace std;

int main() {
	int data[10] = { 9, 17, 5, 6, 124, 112,1,3,87,55 };
	int max = 10;
	//data[0] 기준 값 이미 정렬되었다고 가정 (1개 확립되고 시작)
	for (int i = 1; i < max; i++) { //그래서 i =1
		int key = data[i]; //비교대상자
		int j = i - 1;// 확립된 인덱스의 끝
		while (j >= 0 && data[j] > key) { // j index가 -1이 되징낳게 조건을 걸고, 비교 대상자와 확립된 인덱스의 끝과 비교를한다.
			data[j + 1] = data[j]; //key에는 j+1 index값이 있기 때문에 그냥 바로 덮어씌운다.
			j--; //다음 확립된 인덱스를 위해서 감소를 시키고 while문으로 들어가서 조건문을 본다.
		}
		data[j + 1] = key; //while문을 들어갔을 때 temp가 없이 덮어 씌워졌다.
		//그것은 key에 값이 있기 때문이다. data[j+1]에 그러므로 key의 값을 넣어준다.
		//while문에 안들어가면 똑같은 자리에 똑같은 값을 넣어주는 것이기 때문에 상관없다.
	}

	for (int i = 0; i < max; i++) {
		cout << data[i] << " ";
	}
}