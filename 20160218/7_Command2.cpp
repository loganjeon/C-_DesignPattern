// 7_Command2
#include <vector>
#include <iostream>
using namespace std;

// �ٽ� : ����� ��ü�� ĸ��ȭ
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

// ������ �߰��ϴ� ����� �θ� Ŭ������ �����ؾ� �Ѵ�.
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

	// Factory Method ����
	// : Template Method ������ ����ε�, �ڽ��� ������ �ϴ� �����Լ���
	//   �˰��� �����̳� ��å�� �ƴ�, ��ü�� ������ ��
	virtual void execute() { v.push_back(createShape()); }
	virtual Shape* createShape() = 0;
};

// �簢���� �߰��ϴ� ���
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
// ���� ����� ���� ��ũ�� ��ɵ� ���� �� �ִ�. - Composite Pattern
//  : ����� �ռ��� ���� ���� ��ü�� ����
class MacroCommand : public ICommand
{
	vector<ICommand*> v;		// �������� ���
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