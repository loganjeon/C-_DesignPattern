// 3_관찰자
#include <iostream>
#include <vector>
using namespace std;

// 클래스 디자인의 핵심
// 1. 변하지 않는 공통의 요소 : 부모로 제공한다.
// 2. 변하게 되는 것 : 가상함수로 제공한다.


// 개념 : 하나의 이벤트를 여러 객체에게 전달
struct IObserver
{
	virtual void onUpdate(void* data) = 0;
	virtual ~IObserver() {}
};

// 관찰의 대상 : 표
class Table
{
	vector<IObserver*> v;
	int data[5];
public:
	Table() { memset(data, 0, sizeof(data)); }

	void attach(IObserver* p) { v.push_back(p); }
	void detach(IObserver* p) {}

	void notify(void* p)
	{
		for (int i = 0; i < v.size(); ++i)
			v[i]->onUpdate(p);
	}

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

int main()
{
	Table table;
	PieGraph pg;
	BarGraph bg;

	table.attach(&pg);
	table.attach(&bg);

	table.edit();
}


