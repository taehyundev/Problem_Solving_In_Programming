#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int data[9] = { 1,30,20,3,4,2,8,9,10 };
	sort(data, data + 9);
	for (int i = 0; i < 9; i++) {
		cout << data[i] << " ";
	}
}