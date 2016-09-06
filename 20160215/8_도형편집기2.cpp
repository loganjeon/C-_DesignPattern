#include <vector>
#include <iostream>
using namespace std;

// 8_����������2
// 5. ����� �߰��Ǿ, (��� Ȯ�忡 �����ְ�, Open)
//    ���� �ڵ�� �����Ǹ� �ȵȴ�. (�ڵ� �������� ������ �Ѵ�, Close)
//    OCP - Open Closed Principle

// 6. �������� OCP�� �����Ѵ�.
// 7. Prototype Pattern : ������ �����ϴ� ��ü�� ���� �ؼ� ���ο� ��ü��
//                        ����� ���.
//                        clone() ���� �Լ�
//           Java : Cloneable, C# : ICloneable,  ObjC:Copyable

// 8. Replace type code with Polymorphism
// 9. DRY : Do not repeat yourself - �ߺ����� ����.

// 10. ���ϴ� �Ͱ� ������ �ʴ� ���� �и��Ǿ�� �Ѵ�.
//   "���뼺�� �������� �и�"
// ��� 1. ������ �ʴ� ��ü �帧���� ���ؾ� �ϴ� �κ��� ã�Ƽ�
//         �����Լ��� �и��Ѵ�.

// http://d.pr/n/1iKv8
// 11. NVI - Non Virtual Interface(Template Method)
//  : ������ �ʴ� ��ü �˰����� �θ� �񰡻��Լ��� �����ϰ�,
//    ���ؾ� �ϴ� �κ��� �����Լ�ȭ�ؼ� �ڽ� Ŭ������ �����ϰ� �� �� �ִ� ���.
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
	// ���� ��ȯ ��Ģ�� ���� ���� Ÿ���� �����ϴ� ���� �����ϴ�.
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
			cout << "���° ������ �����ұ��? >> ";
			int k;
			cin >> k;

			v.push_back(v[k]->clone());

			// k��° ������ ���纻�� ���� v�� �߰��Ѵ�.
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


















