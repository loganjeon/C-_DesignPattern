// 1_�湮��3
// http://d.pr/n/g5TC

#include <string>
#include <vector>
#include <iostream>

#include <conio.h>
using namespace std;

class PopupMenu;
class MenuItem;
struct IMenuVisitor
{
	virtual void visit(PopupMenu* p) = 0;
	virtual void visit(MenuItem* p) = 0;
	virtual ~IMenuVisitor() {}
};

struct IMenuAcceptor
{
	virtual void accept(IMenuVisitor* visitor) = 0;
	virtual ~IMenuAcceptor() {}
};


class BaseMenu : public IMenuAcceptor
{
	string name;
public:
	BaseMenu(string s) : name(s) {}
	virtual ~BaseMenu() {}

	string getName() { return name; }
	void setName(string s) { name = s; }  //!!!! ĸ��ȭ ���� ����

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
public:
	virtual void accept(IMenuVisitor* p)
	{
		p->visit(this);  // �ڽ��� �����Ѵ�.
	}


	MenuItem(string s) : BaseMenu(s) {}

	void command()
	{
		cout << getName() << " �޴��� ���õǾ���." << endl;
		getch();
	}
};

#define clrscr() system("cls")

class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v;  
public:
	// �ٽ�!!!
	virtual void accept(IMenuVisitor* p)
	{
		p->visit(this);

		for (int i = 0; i < v.size(); ++i)
			v[i]->accept(p);
	}




	PopupMenu(string s) : BaseMenu(s) {}
	void addMenu(BaseMenu* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			clrscr();

			int sz = v.size();
			for (int i = 0; i < sz; ++i) {
				cout << i + 1 << ". " << v[i]->getName() << endl;
			}
			cout << sz + 1 << ". ���� �޴���" << endl;

			cout << "�޴��� �����ϼ���. >> ";
			int cmd;
			cin >> cmd;

			if (cmd == sz + 1)  // ���� �޴���
				break;

			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue;

			// ���õ� �޴��� �����Ѵ�. ��� �ұ��?
			v[cmd - 1]->command();  // ������. �ٽ�!!!!
		}
	}
};

// �޴� �ý��ۿ� �پ��� ����� �����ϴ� �湮�ڸ� �����ϸ� �˴ϴ�.
// �޴� ���� Ŭ������ ��� �Լ��� �߰����� �ʾƵ� ����� �߰��� �ֽ��ϴ�.
class TitleDecorator : public IMenuVisitor
{
public:
	virtual void visit(MenuItem* p) {}
	virtual void visit(PopupMenu* p)
	{
		string title = p->getName();
		title += "  >";

		p->setName(title);
	}
};


int main()
{
	PopupMenu* menubar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("ȭ�� ����");
	PopupMenu* p2 = new PopupMenu("�Ҹ� ����");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(new MenuItem("�ػ� ����"));
	p1->addMenu(new MenuItem("���� ����"));
	p1->addMenu(new MenuItem("��Ÿ ����"));

	p2->addMenu(new MenuItem("���� ����"));
	p2->addMenu(new MenuItem("���� ����"));

	TitleDecorator td;
	menubar->accept(&td);

	// ���� �����Ϸ���?
	menubar->command();
}