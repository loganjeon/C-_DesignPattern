// 3_관찰자
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
// 관찰의 대상 : 표
// 핵심 : 모든 관찰의 대상의 로직은 항상 동일하다. 부모로 제공하자!
class Subject
{
	vector<IObserver*> v;
public:
	Subject()
	{
		// 1. 약속된 폴더의 모든 DLL을 열거한다.
		IoEnumFiles("D:\\plugin", "*.dll", LoadModule, this);
	}

	// 아래 함수가 static인 이유를 정확히 알아야 합니다.
	static int LoadModule(string name, void* param)
	{
		cout << name << endl;

		// 2. DLL Load : dlopen()
		void* addr = IoLoadModule(name);

		// 3. 약속된 함수인 CreateGraph를 찾는다. : dlsym()
		typedef IObserver* (*FP)();
		FP f = (FP)IoGetFunctionAddress(addr, "CreateGraph");

		// 4. 그래프 생성
		IObserver* p = f();

		// 5. 관찰자로 등록한다.
		Subject* self = static_cast<Subject*>(param);
		self->attach(p);
		
		return 1;   // 계속 열거해달라.
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

			// 모든 관찰자에게 알려준다.
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


