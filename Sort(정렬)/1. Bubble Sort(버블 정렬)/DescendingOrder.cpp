// 내림차순
#include <iostream>
using namespace std;

int main() {
	int data[10] = { 9, 17, 5, 6, 124, 112,1,3,87,55 };
	int max = 10;
	int temp;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max-1; j++) {
			if (data[j] < data[j+1]) { //여기만 오름차순이랑 다르게 부등호를 반대로 하면 됨
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}

	for(int i=0; i<max; i++)
		cout << data[i]<<" " << endl;
}