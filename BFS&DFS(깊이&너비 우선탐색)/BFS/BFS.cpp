#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int number = 7;
int c[7];
vector<int> a[8];

void bfs(int start) {
	queue<int> q;
	q.push(start); //ù Vertax�� push ���ش�.
	c[start] = true; //vertax�� �湮 �߱⿡ true�� ǥ�����ش�.
	while (!q.empty()) { //vertax�� ��� �湮 �Ǿ��ٸ� empty�� true�� �ȴ�.
						// �׷��� ������ �湮 �ȵǾ��� ���� �ȴ�.
		int x = q.front();//fornt�� push�� ���� x�� ����ش�.
		q.pop(); // x�� ���� ���� pop���� ���� ���ش�.
		cout << x<<" ";// ����Ѵ�.
		for (int i = 0; i < a[x].size(); i++) {  //������ x�� ������ ������ �����ֱ� ���ؼ� a[x].size ��ŭ ���������ش�.
			int y = a[x][i]; //x�� ������ vertax�� y�� ��´�.
			if (!c[y]) { // true�� �ƴ� �� �湮�� ������ ��
				q.push(y); //�� vertax���� �����ϱ����ؼ� push�� ���ش�.
				c[y] = true; //�� vertax�� �湮 ǥ�ø� ���� true���� �־��ش�.
			}
		}
	}
}

int main() {
	a[1].push_back(2);
	a[2].push_back(1);


	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);


	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);


	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(6);
	a[7].push_back(7);
	bfs(1);
	return 0;
}