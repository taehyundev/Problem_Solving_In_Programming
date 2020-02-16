//오름차순
#include <iostream>
using namespace std;

int main() {
	int data[10] = { 9, 17, 5, 6, 124, 112,1,3,87,55 };
	int max = 10;
	int temp;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max-1; j++) {  //마지막은 비교를 안해도되기때문에 max+1이 될 수는 없어서
			if (data[j] > data[j+1]) {
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}

	for(int i=0; i<max; i++)
		cout << data[i]<<" ";
}

//비효율적
