#include <iostream>

using namespace std;

const int number = 15;

typedef struct node* treePoint;
typedef struct node {
	int data;
	treePoint leftChild, rightChild;
}node;

void preorder(treePoint ptr) {
	if (ptr) { // ptr root?
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);

	}
}
void postorder(treePoint ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

void inorder(treePoint ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}
void main() {
	node n[number + 1];
	for (int i = 1; i <= number; i++) {
		n[i].data = i;
		n[i].leftChild = NULL;
		n[i].rightChild = NULL;
	}

	for (int i = 0; i <= number; i++) {
		if (i % 2 == 0)
			n[i / 2].leftChild = &n[i];
		else
			n[i / 2].rightChild = &n[i];
	}
	cout << "전위 순회 : " ;
	preorder(&n[1]);
	cout << endl;
	
	cout << "중위 순회 : ";
	inorder(&n[1]);
	cout << endl;

	cout << "휘위 순회 : ";
	postorder(&n[1]);
	cout << endl;
}