## BFS 설명

BFS 는 보통 Queue를 이용한다.

> 모든 경우를 다 돌면서 탐색하는 것을 원칙으로 함

## DFS 설명

DFS 는 보통 재귀함수를 이용한다.

> 한곳으로 끝까지 파고드는 것을 원칙으로함


둘 다 조건이 없다는 가정하에 재귀를 사용하는 DFS가 코드상으로 더 짧다. 하지만 여러 경우를 고려한다면 BFS를 쓰는것이 더 효율적이다.

```c++ 
//BFS 예시 미로탐색
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int Goal_x, Goal_y;
int map[101][101];
int dir[4][2] = { {1,0},{-1,0}, {0,1},{0,-1} }; //x, y
int visitBfs[101][101];

bool check(int x,int y) {
	return (0 <= x) && (x < Goal_x) && (0 <= y) && (y < Goal_y);
}

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	visitBfs[x][ y] = 1;
	q.push(pair<int, int>(x,y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][1];
			int next_y = y + dir[i][0];
			if (check(next_x,next_y) ==true && visitBfs[next_x][next_y] ==0 && map[next_x][next_y]==1) {
				
				visitBfs[next_x][next_y] = visitBfs[x][y] + 1;
				q.push(pair<int, int>(next_x, next_y));
			}
		}
	}
	return visitBfs[Goal_x - 1][Goal_y - 1];
}

int main() {
	cin >> Goal_x >> Goal_y;
	for (int i = 0; i < Goal_x; i++) {
		for (int j = 0; j < Goal_y; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	cout<<bfs(0, 0);
}

```
```C++ 
//DFS 예시 
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

int num;
int graph[26][26];
int DFS_visit[26][26];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int cnt = 0;
int s[323];
int maxm = 0;
int in(int x,int y) {
	return ((0 <= x) && (x < num)) && ((0 <= y) && (y < num));
}
int DFS(int x, int y) {

	DFS_visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (in(nx, ny) && DFS_visit[nx][ny] == 0 && graph[nx][ny]!=0) {
			DFS_visit[nx][ny] = 1;
			graph[nx][ny] = graph[x][y] + 1;
			maxm++;
			DFS(nx, ny);
		}
	}
	return maxm;
}

int main() {
	int k = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (graph[i][j] == 1 && DFS_visit[i][j] == 0) {
				cnt++;
				s[k] = (DFS(i, j) + 1);
				k++;
				maxm=0;
			}
		}
	}
	cout << cnt << endl;
	sort(s, s + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << s[i] << endl;
	}
}
```

보통 위와 같이 동작된다. dir이라는 변수와 같은 기능으로 상하 좌우 모두 살펴보는 형태가 된다.
DFS는 끝까지 들어가서 나왔다가 다음 곳으로 가는 형태
BFS는 애초부터 여러곳을 다 들어가는 형태로 표현된다.
