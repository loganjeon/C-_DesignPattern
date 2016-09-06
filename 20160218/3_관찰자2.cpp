// 3_������
#include <iostream>
#include <vector>
using namespace std;

#include "IObserver.h"

// IObserver.h
#if 0
struct IObserver
{
	virtual void onUpdate(void* data) = 0;
	virtual ~IObserver() {}
};
#endif

#include "ioacademy.h"
using namespace ioacademy;
// ������ ��� : ǥ
// �ٽ� : ��� ������ ����� ������ �׻� �����ϴ�. �θ�� ��������!
class Subject
{
	vector<IObserver*> v;
public:
	Subject()
	{
		// 1. ��ӵ� ������ ��� DLL�� �����Ѵ�.
		IoEnumFiles("D:\\plugin", "*.dll", LoadModule, this);
	}

	// �Ʒ� �Լ��� static�� ������ ��Ȯ�� �˾ƾ� �մϴ�.
	static int LoadModule(string name, void* param)
	{
		cout << name << endl;

		// 2. DLL Load : dlopen()
		void* addr = IoLoadModule(name);

		// 3. ��ӵ� �Լ��� CreateGraph�� ã�´�. : dlsym()
		typedef IObserver* (*FP)();
		FP f = (FP)IoGetFunctionAddress(addr, "CreateGraph");

		// 4. �׷��� ����
		IObserver* p = f();

		// 5. �����ڷ� ����Ѵ�.
		Subject* self = static_cast<Subject*>(param);
		self->attach(p);
		
		return 1;   // ��� �����ش޶�.
	}

	void attach(IObserver* p) { v.push_back(p); }
	void detach(IObserver* p) {}

	void notify(void* p)
	{
		for (int i = 0; i < v.size(); ++i)
			v[i]->onUpdate(p);
	}
};

class Table : public Subject
{
	int data[5];
public:
	Table() { memset(data, 0, sizeof(data)); }

	void edit()
	{
		while (1)
		{
			int index;
			cout << "index : "; cin >> index;
			cout << "data: "; cin >> data[index];

			// ��� �����ڿ��� �˷��ش�.
			notify(data);
		}
	}
};

//----------------------------------------
class BarGraph : public IObserver
{
public:
	void onUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "********* Bar Graph *********" << endl;
		for (int i = 0; i < 5; i++)
			cout << i << " : " << data[i] << endl;
	}
};

class PieGraph : public IObserver
{
public:
	void onUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "********* Pie Graph *********" << endl;
		for (int i = 0; i < 5; i++)
			cout << i << " : " << data[i] << endl;
	}
};

// http://d.pr/n/11C5e
int main()
{
	Table table;
	PieGraph pg;
	BarGraph bg;

	table.attach(&pg);
	table.attach(&bg);

	table.edit();
}


