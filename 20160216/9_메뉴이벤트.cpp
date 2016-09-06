// 9_�޴��̺�Ʈ
#include <iostream>
using namespace std;

// http://d.pr/n/1amKZ
// 1. �������̽� ����� ������ ���� : Java, Android
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
		// �޴��� ���õ� ����� �ٽ� �ܺο� �˷��� �Ѵ�.
		// "��ü�� �ܺη� �̺�Ʈ�� �߻��Ѵ�." ��� ǥ��
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