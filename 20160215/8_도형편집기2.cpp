#include <vector>
#include <iostream>
using namespace std;

// 8_도형편집기2
// 5. 기능이 추가되어도, (기능 확장에 열려있고, Open)
//    기존 코드는 수정되면 안된다. (코드 수정에는 닫혀야 한다, Close)
//    OCP - Open Closed Principle

// 6. 다형성은 OCP를 만족한다.
// 7. Prototype Pattern : 기존에 존재하는 객체를 복사 해서 새로운 객체를
//                        만드는 방법.
//                        clone() 가상 함수
//           Java : Cloneable, C# : ICloneable,  ObjC:Copyable

// 8. Replace type code with Polymorphism
// 9. DRY : Do not repeat yourself - 중복하지 마라.

// 10. 변하는 것과 변하지 않는 것은 분리되어야 한다.
//   "공통성과 가변성의 분리"
// 방법 1. 변하지 않는 전체 흐름에서 변해야 하는 부분을 찾아서
//         가상함수로 분리한다.

// http://d.pr/n/1iKv8
// 11. NVI - Non Virtual Interface(Template Method)
//  : 변하지 않는 전체 알고리즘은 부모가 비가상함수로 제공하고,
//    변해야 하는 부분은 가상함수화해서 자식 클래스가 변경하게 할 수 있는 기법.
class Shape
{
public:
	void draw()
	{
		cout << "mutex lock" << endl;
		drawImpl();
		cout << "mutex unlock" << endl;
	}
	virtual Shape* clone() { return new Shape(*this); }

protected:
	virtual void drawImpl() {}
};

class Rect : public Shape
{
public:
	void drawImpl()
	{
		cout << "Rect draw" << endl;
	}
	// 공변 반환 법칙에 의해 리턴 타입을 변경하는 것이 가능하다.
	// Java : 1.5
	Rect* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void drawImpl()
	{ 
		cout << "Circle draw" << endl;
	}
	Circle* clone() { return new Circle(*this); }
};

int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 8) {
			cout << "몇번째 도형을 복사할까요? >> ";
			int k;
			cin >> k;

			v.push_back(v[k]->clone());

			// k번째 도형의 복사본을 만들어서 v에 추가한다.
			// v[k] : Rect? Circle?
			/*
			switch (v[k]->type)
			{
			case 1: //Rect 
			case 2: //Circle
			}
			*/

		}
		else if (cmd == 9) {
			for (int i = 0; i < v.size(); ++i)
				v[i]->draw();
		}
	}
}


















