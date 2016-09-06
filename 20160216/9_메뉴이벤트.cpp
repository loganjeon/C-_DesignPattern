// 9_메뉴이벤트
#include <iostream>
using namespace std;

// http://d.pr/n/1amKZ
// 1. 인터페이스 기반의 리스너 개념 : Java, Android
struct IMenuListener
{
	virtual void onCommand(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem
{
	int id;
	IMenuListener* pListener;
public:
	MenuItem(int n) : id(n), pListener(0) {}
	void setListener(IMenuListener* p) { pListener = p; }

	virtual void command()
	{
		// 메뉴가 선택된 사실을 다시 외부에 알려야 한다.
		// "객체가 외부로 이벤트를 발생한다." 라고 표현
		pListener->onCommand(id);
	}
};

// http://d.pr/n/16pdQ
class Dialog : public IMenuListener
{
public:
	virtual void onCommand(int id)
	{
		switch (id)
		{
		case 11: open(); break;
		case 12: close(); break;
		}
		
	}

	void close() { cout << "Dialog close" << endl; }
	void open() { cout << "Dialog open" << endl; }
};

int main()
{
	MenuItem open(11), close(12);
	Dialog dialog;
	open.setListener(&dialog);
	close.setListener(&dialog);

	open.command();
	close.command();
}