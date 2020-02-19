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
	bool operator < (Student& student) { //�� ��ü�� ���ؼ�
		return this->score < student.score;
		// ������ ���� �������
	}
};

int main() {
	Student students[] = {
		Student("ȫ�浿", 90),
		Student("���°�", 93),
		Student("�����", 97),
		Student("������", 87),
		Student("�̼���", 92),
	};
	sort(students, students + 5);
	//sort�Լ� ������ ��Ű�鼭 �����ϴ� ����
	//���� ���� Ŭ������ �̿��� �۾��ϸ� �˴ϴ�.

	for (int i = 0; i < 5; i++) {
		cout << students[i].name << " ";
			
	}
}