#include <iostream>
using namespace std;

// 도형편집기
// 1. 모든 도형을 타입화하면 편리하다.
// 2. 모든 도형의 공통의 부모가 있다면 모든 도형을 묶어서 관리할 수 있다.
// 3. 모든 도형의 공통의 특징이 있다면, 반드시 부모에도 있어야 한다.
//    그래야 부모 포인터 묶어서 사용할 때 해당 특징을 이용할 수 있다.
//    LSP(Liskov Substitution Principle) 이라는 개념.

// 4. 부모의 함수중 자식이 재정의하는 모든 함수는 가상함수이어야 한다.
//   "가상함수가 아닌 함수는 재정의하지도 말라"

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


















