#include <iostream>
#include <algorithm>

using namespace std;


class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	bool operator < (Student& student) { //이 객체에 한해서
		return this->score < student.score;
		// 점수가 낮은 순서대로
	}
};

int main() {
	Student students[] = {
		Student("홍길동", 90),
		Student("강태공", 93),
		Student("김맹자", 97),
		Student("강공자", 87),
		Student("이순재", 92),
	};
	sort(students, students + 5);
	//sort함수 문법을 지키면서 구현하는 것은
	//위와 같이 클래스를 이용해 작업하면 됩니다.

	for (int i = 0; i < 5; i++) {
		cout << students[i].name << " ";
			
	}
}