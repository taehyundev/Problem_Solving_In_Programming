#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int number = 7;
int c[7];
vector<int> a[8];

void bfs(int start) {
	queue<int> q;
	q.push(start); //첫 Vertax를 push 해준다.
	c[start] = true; //vertax를 방문 했기에 true로 표기해준다.
	while (!q.empty()) { //vertax가 모두 방문 되었다면 empty가 true가 된다.
						// 그렇기 떄문에 방문 안되었을 때가 된다.
		int x = q.front();//fornt로 push한 값을 x에 담아준다.
		q.pop(); // x에 담은 이후 pop으로 값을 빼준다.
		cout << x<<" ";// 출력한다.
		for (int i = 0; i < a[x].size(); i++) {  //꺼내준 x와 인접한 노드들을 꺼내주기 위해서 a[x].size 만큼 증감시켜준다.
			int y = a[x][i]; //x의 인접한 vertax를 y에 담는다.
			if (!c[y]) { // true가 아닐 때 방문을 안했을 때
				q.push(y); //그 vertax부터 시작하기위해서 push를 해준다.
				c[y] = true; //그 vertax는 방문 표시를 위해 true값을 넣어준다.
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