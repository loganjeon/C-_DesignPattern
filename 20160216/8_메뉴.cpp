#include <string>
#include <vector>
#include <iostream>

#include <conio.h>
using namespace std;
// 8_�޴�
// http://d.pr/n/13X40


// Composite Pattern
// ���� ��ü(MenuItem) / ���� ��ü(PopupMenu)
// 1. ���� ��ü�� ���� ��ü�� ���� ��ü�� ��� ������ �� �־�� �Ѵ�.
//  : ���� ��ü�� ���� ��ü�� ���� �θ� ������ �Ѵ�.
// 2. ���� ��ü�� ���� ��ü�� ���Ͻ� �ȴ�.
//  : ������ ����. (��� command()�� �ִ�.)
//  : command() �����Լ��� �θ� Ŭ������ �־�� �Ѵ�.

class BaseMenu
{
	string name;
public:
	BaseMenu(string s) : name(s) {}
	virtual ~BaseMenu() {}

	string getName() { return name; }

	// �θ� ���忡���� �������� ������ ����, �ڽ��� �ݵ�� ������ �Ѵٸ�
	// ���� �����Լ��� ����.
	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
public:
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
	vector<BaseMenu*> v;   // �ٽ�!!!
public:
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

	// ���� �����Ϸ���?
	menubar->command();
}