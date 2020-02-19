#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<int, string>> v;
	v.push_back((pair<int, string>(80, "강감찬")));
	v.push_back((pair<int, string>(90, "지렁이")));
	v.push_back((pair<int, string>(81, "다람쥐")));
	v.push_back((pair<int, string>(83, "임당이")));
	v.push_back((pair<int, string>(93, "김길동")));

	sort(v.begin(),v.end()); // 벡터를 정렬 할때는 begin 시작지와 end 도착지를 잘 표기하면 된다.
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " "; //second는 두번쨰 항목을 의미
	}
}
