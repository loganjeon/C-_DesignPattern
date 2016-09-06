// 7_Command
#include <vector>
#include <iostream>
using namespace std;

// �ٽ� : ����� ��ü�� ĸ��ȭ
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

// ��� ����� ��üȭ �Ѵ�. ������ �ϳ��� ��� �����ؾ� �ϱ� ������
// ������ �θ�, �� �������̽��� �ʿ��ϴ�.
struct ICommand
{
	virtual void execute() = 0;

	// �ڹ� 8������ �������̽����� �⺻ ������ ���� �� �ֽ��ϴ�.
	// "default method" 
	virtual void undo() {}
	virtual bool canUndo() { return false; }

	virtual ~ICommand() {}
};

// �簢���� �߰��ϴ� ���
class AddRectCommand : public ICommand
{
	vector<Shape*>& v;
public:
	AddRectCommand(vector<Shape*>& p) : v(p) {}
	
	virtual void execute() { v.push_back(new Rect); }
	virtual bool canUndo() { return true; }
	virtual void undo() {
		Shape* p = v.back();  // ���ϸ��ϰ� �������� �ʽ��ϴ�.
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