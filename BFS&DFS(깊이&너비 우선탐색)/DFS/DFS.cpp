#include <iostream>
#include <vector>
using namespace std;
int number = 7;
int c[8];
vector<int> a[8];

void dfs(int x) {
	if (c[x]) return; //재귀함수를 빠져나가게 하기 위해서 다 방문했을 시 return을 썼다.

	c[x] = true; //방문
	cout << x << ' '; // 출력
	for (int i = 0; i < a[x].size(); i++) {//인접한 vertax를 for문으로 돌림
		int y = a[x][i]; 
		dfs(y); //재귀를 이용해서 깊게 들어가서 막장을 만나면 위에 조건으로 return이 된다. 그러면 다음 for문 으로 넘어가게된다. (백트랙킹 개념)
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
	dfs(1);
	return 0;
}