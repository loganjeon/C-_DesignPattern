// SampleGraph.cpp

#include "IObserver.h"

#include <iostream>
using namespace std;

class SampleGraph : public IObserver
{
public:
	void onUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "********* Sample Graph *********" << endl;
		for (int i = 0; i < 5; i++)
			cout << i << " : " << data[i] << endl;
	}
};


// SampleGraph ��� �̸��� ���� DLL�� ����� ����� �˰� �ֽ��ϴ�.
// .exe ������ ���� �̸��� �� �� �����ϴ�.
// �׷���, DLL�� �����ڴ� �ڽ��� ���� Ŭ������ ��ü�� ������ �� �ִ�
// ����� ������ �־�� �մϴ�.

// �Լ� �ϳ��� ����մϴ�.
extern "C"					// ������ �� �� �Լ� �̸��� �������� ����� ��
__declspec(dllexport)       // �����쿡�� DLL�� ���� �� �ʿ�.
IObserver* CreateGraph()
{
	return new SampleGraph;
}

// /LD : DLL ����� �ɼ�
// cl SampleGraph.cpp /LD

// D:\plugin ������ ���弼��. SampleGraph.dll�� ������ �־�μ���.