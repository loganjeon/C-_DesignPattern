// 7_Command
#include <vector>
#include <iostream>
using namespace std;

// 핵심 : 명령을 객체로 캡슐화
// http://d.pr/n/10BTB

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

// 모든 명령을 객체화 한다. 하지만 하나로 묶어서 관리해야 하기 때문에
// 공통의 부모, 즉 인터페이스가 필요하다.
struct ICommand
{
	virtual void execute() = 0;

	// 자바 8에서는 인터페이스에도 기본 구현을 넣을 수 있습니다.
	// "default method" 
	virtual void undo() {}
	virtual bool canUndo() { return false; }

	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
class AddRectCommand : public ICommand
{
	vector<Shape*>& v;
public:
	AddRectCommand(vector<Shape*>& p) : v(p) {}
	
	virtual void execute() { v.push_back(new Rect); }
	virtual bool canUndo() { return true; }
	virtual void undo() {
		Shape* p = v.back();  // 리턴만하고 제거하지 않습니다.
		v.pop_back();

		delete p;
	}
};

class AddCircleCommand : public ICommand
{
	vector<Shape*>& v;
public:
	AddCircleCommand(vector<Shape*>& p) : v(p) {}

	virtual void execute() { v.push_back(new Circle); }
	virtual bool canUndo() { return true; }
	virtual void undo() {
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
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

// http://d.pr/n/1gxX2
#include <stack>

int main()
{
	vector<Shape*> v;
	stack<ICommand*> undo;
	stack<ICommand*> redo;

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
		} else if (cmd == 6) {
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