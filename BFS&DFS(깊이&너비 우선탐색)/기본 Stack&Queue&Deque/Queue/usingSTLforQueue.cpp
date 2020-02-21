#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;
	q.push(10);
	q.push(7);
	q.push(1);
	q.pop();
	q.push(3);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}