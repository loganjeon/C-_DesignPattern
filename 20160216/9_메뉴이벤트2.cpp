// 9_�޴��̺�Ʈ
// http://d.pr/n/1jg3J
#include <iostream>
#include <vector>
using namespace std;

struct IMenuListener
{
	virtual void onCommand(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem
{
	int id;
	vector<IMenuListener*> listeners;
public:
	MenuItem(int n) : id(n) {}
	void addListener(IMenuListener* p) { listeners.push_back(p); }

	virtual void command()
	{
		// ��ϵ� ��� ��ü���� �˷��ش�. - ������(Observer) ����
		for (IMenuListener* e : listeners)  // ranged-for 
			e->onCommand(id);
	}
};

int main()
{
}