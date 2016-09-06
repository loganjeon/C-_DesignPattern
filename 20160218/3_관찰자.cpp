// 3_������
#include <iostream>
#include <vector>
using namespace std;

// Ŭ���� �������� �ٽ�
// 1. ������ �ʴ� ������ ��� : �θ�� �����Ѵ�.
// 2. ���ϰ� �Ǵ� �� : �����Լ��� �����Ѵ�.


// ���� : �ϳ��� �̺�Ʈ�� ���� ��ü���� ����
struct IObserver
{
	virtual void onUpdate(void* data) = 0;
	virtual ~IObserver() {}
};

// ������ ��� : ǥ
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

int main()
{
	Table table;
	PieGraph pg;
	BarGraph bg;

	table.attach(&pg);
	table.attach(&bg);

	table.edit();
}


