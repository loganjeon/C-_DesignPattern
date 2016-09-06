#include <string>
#include <vector>
#include <iostream>

#include <conio.h>
using namespace std;
// 8_메뉴
// http://d.pr/n/13X40


// Composite Pattern
// 단일 객체(MenuItem) / 복합 객체(PopupMenu)
// 1. 복합 객체는 단일 객체와 복합 객체를 모두 보관할 수 있어야 한다.
//  : 단일 객체와 복합 객체는 동일 부모를 가져야 한다.
// 2. 단일 객체와 복합 객체가 동일시 된다.
//  : 사용법이 같다. (모두 command()가 있다.)
//  : command() 가상함수가 부모 클래스에 있어야 한다.

class BaseMenu
{
	string name;
public:
	BaseMenu(string s) : name(s) {}
	virtual ~BaseMenu() {}

	string getName() { return name; }

	// 부모 입장에서는 구현해줄 내용이 없고, 자식이 반드시 만들어야 한다면
	// 순수 가상함수가 좋다.
	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
public:
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
	vector<BaseMenu*> v;   // 핵심!!!
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

	// 이제 시작하려면?
	menubar->command();
}