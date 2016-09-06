#include <iostream>
using namespace std;

// ����������
// 1. ��� ������ Ÿ��ȭ�ϸ� ���ϴ�.
// 2. ��� ������ ������ �θ� �ִٸ� ��� ������ ��� ������ �� �ִ�.
// 3. ��� ������ ������ Ư¡�� �ִٸ�, �ݵ�� �θ𿡵� �־�� �Ѵ�.
//    �׷��� �θ� ������ ��� ����� �� �ش� Ư¡�� �̿��� �� �ִ�.
//    LSP(Liskov Substitution Principle) �̶�� ����.

// 4. �θ��� �Լ��� �ڽ��� �������ϴ� ��� �Լ��� �����Լ��̾�� �Ѵ�.
//   "�����Լ��� �ƴ� �Լ��� ������������ ����"

// http://d.pr/n/noNB
class Shape
{
public:
	virtual void draw() {}
};

class Rect : public Shape
{
public:
	void draw()
	{ cout << "Rect draw" << endl; }
};

class Circle : public Shape
{
public:
	void draw() { cout << "Circle draw" << endl; }
};

#include <vector>
int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9) {
			for (int i = 0; i < v.size(); ++i)
				v[i]->draw();
		}
	}
}


















