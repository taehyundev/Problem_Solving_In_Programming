#include <iostream>
using namespace std;
#define max 9

int heap[9] = { 8,7,6,5,4,3,2,1,9 };

int main() {
	//root�� ã�� ����
	//�ִ� �� ���� 
	for (int i = 1; i < max; i++) { // root�� �����ϰ� �ݺ� 
		int child = i;
		do {
			int root = (child - 1) / 2; //ù root�� 0 

			if (heap[root] < heap[child]) {
				int temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}
			child = root;
		} while (child != 0); //�ڽ��� root�� �ȵ� �� ���� 
	}

	for (int i = 0; i < max; i++) {
		cout << heap[i] << " ";
	}
	cout << endl;
	// 9 8 6 7 4 3 2 1 5

	//index 0��°�� root�� �������� 
	for (int i = max - 1; i >= 0; i--) {
		int temp = heap[0];
		cout << heap[0] << endl; //������ ���ؼ� root�� �׻� ũ�� ������ root�� �������� �ű�� �ű�� �����ϰ� root�� ã�� �� root�� �ű�� ����
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0; //root�� ���� 
		int child = 1; //�ڽ��� ���� 
		do {
			child = 2 * root + 1; //�ڽ� ã�� i���� �۾ƾ���

			if (child < i - 1 && heap[child] < heap[child + 1]) { //�ڽ��߿� ū �ڽ��� �� �ڽ� ++ vs �ڽ�
				child++;
			}

			//�������� �ڸ��̵�
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
���� �� : 9 8 6 7 4 3 2 1 5
1 : 5 8 6 7 4 3 2 1 9  9�� �ڷο�
root�� �ٽ� ã��
2 : 1 7 6 5 4 3 2 8 9 8�� 9�����ο�(8�� root�ڸ��� ����)
root�� �ٽ� ã��
3 : 2 5 6 1 4 3 7 8 9 7�� 8������ ��
root�� �ٽ� ã��
4 : 2 5 3 1 4 6 7 8 9
root�� �ٽ� ã��
5 : 2 4 3 1 5 6 7 8 9
root�� �ٽ� ã��
6 : 1 2 3 4 5 6 7 8 9
root�� �ٽ� ã��
7 : 1 2 3 4 5 6 7 8 9
root�� �ٽ� ã��
8 : 1 2 3 4 5 6 7 8 9
root�� �ٽ� ã��
9 : 1 2 3 4 5 6 7 8 9
��

*/