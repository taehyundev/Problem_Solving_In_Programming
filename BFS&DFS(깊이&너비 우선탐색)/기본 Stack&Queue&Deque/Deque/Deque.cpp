#include <iostream>
#include <deque>

using namespace std;
int main() {
	deque<int> d;
	d.push_front(1);
	d.push_front(2);
	d.push_front(3);
	d.pop_front();
	d.push_front(5);

	cout << "front : ";
	for (int i = 0; i < d.size(); i++) {
		cout << d.front()<< " ";
		d.pop_front();
	}

	d.push_back(4);
	d.push_back(13);
	d.push_back(11);
	cout << endl << "back : ";
	for (int i = 0; i < d.size(); i++) {
		cout << d.back() << " ";
		d.pop_back();
	}
}
