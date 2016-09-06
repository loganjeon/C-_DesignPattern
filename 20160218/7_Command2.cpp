// 7_Command2
#include <vector>
#include <iostream>
using namespace std;

// 핵심 : 명령을 객체로 캡슐화
class Shape
{
public:
	virtual void draw() {}
};

class Rect : public Shape
{
public:
	void draw()
	{
		cout << "Rect draw" << endl;
	}
};

class Circle : public Shape
{
public:
	void draw() { cout << "Circle draw" << endl; }
};

struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() {}
	virtual bool canUndo() { return false; }

	virtual ~ICommand() {}
};

// 도형을 추가하는 명령의 부모 클래스를 제공해야 한다.
class AddCommand : public ICommand
{
	vector<Shape*>& v;
public:
	AddCommand(vector<Shape*>& p) : v(p) {}
	
	virtual bool canUndo() { return true; }
	virtual void undo() {
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}

	// Factory Method 패턴
	// : Template Method 패턴의 모양인데, 자식이 재정의 하는 가상함수가
	//   알고리즘 변경이나 정책이 아닌, 객체의 생성일 때
	virtual void execute() { v.push_back(createShape()); }
	virtual Shape* createShape() = 0;
};

// 사각형을 추가하는 명령
class AddRectCommand : public AddCommand
{
public:
	AddRectCommand(vector<Shape*>& p) : AddCommand(p) {}
	virtual Shape* createShape() { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	AddCircleCommand(vector<Shape*>& p) : AddCommand(p) {}
	virtual Shape* createShape() { return new Circle; }
};

class DrawCommand : public ICommand
{
	vector<Shape*>& v;
public:
	DrawCommand(vector<Shape*>& p) : v(p) {}
	virtual void execute() {
		for (Shape* e : v)
			e->draw();
	}
};

// http://d.pr/n/1801A
// 여러 명령을 묶는 매크로 명령도 만들 수 있다. - Composite Pattern
//  : 재귀적 합성을 통한 복합 객체의 구성
class MacroCommand : public ICommand
{
	vector<ICommand*> v;		// 여러개의 명령
public:
	void addCommand(ICommand* p) { v.push_back(p); }
	virtual void execute()
	{
		for (ICommand* e : v)
			e->execute();
	}
};

// http://d.pr/n/1eTvy
#include <stack>

int main()
{
	vector<Shape*> v;
	stack<ICommand*> undo;
	stack<ICommand*> redo;

	MacroCommand* p = new MacroCommand;
	p->addCommand(new AddRectCommand(v));
	p->addCommand(new AddCircleCommand(v));
	p->addCommand(new DrawCommand(v));
	p->execute();

	while (1)
	{
		int cmd;
		cin >> cmd;

		ICommand* pCommand = 0;

		if (cmd == 1) pCommand = new AddRectCommand(v);
		else if (cmd == 2) pCommand = new AddCircleCommand(v);
		else if (cmd == 9) pCommand = new DrawCommand(v);
		else if (cmd == 5) {
			pCommand = undo.top();
			undo.pop();

			pCommand->undo();
			redo.push(pCommand);
			continue;
		}
		else if (cmd == 6) {
			pCommand = redo.top();
			redo.pop();
		}

		if (pCommand) {
			pCommand->execute();
			if (pCommand->canUndo())
				undo.push(pCommand);
			// delete pCommand;
		}
	}
}