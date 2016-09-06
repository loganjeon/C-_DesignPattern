// 1_방문자3
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
	void setName(string s) { name = s; }  //!!!! 캡슐화 전략 위배

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
public:
	virtual void accept(IMenuVisitor* p)
	{
		p->visit(this);  // 자신을 전달한다.
	}


	MenuItem(string s) : BaseMenu(s) {}

	void command()
	{
		cout << getName() << " 메뉴가 선택되었음." << endl;
		getch();
	}
};

#define clrscr() system("cls")

class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v;  
public:
	// 핵심!!!
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
			cout << sz + 1 << ". 상위 메뉴로" << endl;

			cout << "메뉴를 선택하세요. >> ";
			int cmd;
			cin >> cmd;

			if (cmd == sz + 1)  // 상위 메뉴로
				break;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;

			// 선택된 메뉴를 실행한다. 어떻게 할까요?
			v[cmd - 1]->command();  // 다형성. 핵심!!!!
		}
	}
};

// 메뉴 시스템에 다양한 기능을 제공하는 방문자를 제공하면 됩니다.
// 메뉴 관련 클래스에 멤버 함수를 추가하지 않아도 기능을 추가할 있습니다.
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
	PopupMenu* p1 = new PopupMenu("화면 설정");
	PopupMenu* p2 = new PopupMenu("소리 설정");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(new MenuItem("해상도 설정"));
	p1->addMenu(new MenuItem("색상 설정"));
	p1->addMenu(new MenuItem("기타 설정"));

	p2->addMenu(new MenuItem("볼륨 조절"));
	p2->addMenu(new MenuItem("음색 조절"));

	TitleDecorator td;
	menubar->accept(&td);

	// 이제 시작하려면?
	menubar->command();
}