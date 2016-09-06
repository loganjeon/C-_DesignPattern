// 4_�뺸����(Notification Center)

// ������(Mediator) ����
// : ������ ��ü ���� ���踦 �ܼ�ȭ �����ִ� ��ü
//   �����ο� Ưȭ�� �̽� �Ұ����� �ڵ带 �� ������ ���� �� �ִ�.

// C++ ���� Callback �� ����ϴ� 2���� ���
// 1. �������̽� ������� ��ü ��� - ������ ����
// 2. �Լ� �����ͱ������ �Լ� ��� - �뺸 ����

// http://d.pr/n/lDEg
// ���������� ��� �̺�Ʈ�� ó���ϴ� �뺸 ���͸� ����� ���ô�.
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;

class NotificationCenter
{
	typedef function<void()> HANDLER;

	map<string, vector<HANDLER>> notifi_map;
public:
	void addObserver(string key, HANDLER handler)
	{ 
		notifi_map[key].push_back(handler);
	}

	void postNotificationWithName(string key)
	{
		vector<HANDLER>& v = notifi_map[key];
		for (int i = 0; i < v.size(); ++i)
			v[i]();  // function�� ()�� ȣ���մϴ�.
	}

	// Global / Local �뺸 ����
	static NotificationCenter& defaultCenter()
	{
		static NotificationCenter instance;
		return instance;
	}
};

void foo() { cout << "foo" << endl; }
void goo(int n) { cout << "goo : " << n << endl; }

class Dialog { public: void close() { cout << "Dialog close" << endl; } };

// http://d.pr/n/1hArs
int main()
{
	Dialog dialog;

	NotificationCenter& center = NotificationCenter::defaultCenter();
	center.addObserver("LOWBATTERY", &foo);
	center.addObserver("LOWBATTERY", bind(&Dialog::close, &dialog));

	center.addObserver("MAIL", bind(&goo, 10));

	// ���� ���͸��� üũ�ϴ� ��⿡��
	center.postNotificationWithName("LOWBATTERY");
}