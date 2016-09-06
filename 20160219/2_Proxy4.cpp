// 2_Proxy4
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// ���� ���� �����ڿ��Լ� 2���� ������ �޾ƾ� �մϴ�.
// 1. ICalc.h : �������̽� ���
// 2. CalcProxy.dll : Proxy Ŭ���� ���̺귯��
// http://d.pr/n/1hYjt
#include "ICalc.h"

Ptr<ICalc> CreateInstance()
{
	void* addr = IoLoadModule("CalcProxy.dll");
	typedef ICalc*(*F)();

	F f = (F)IoGetFunctionAddress(addr, "CreateCalc");
	return Ptr<ICalc>(f());
}

// http://d.pr/n/1fsUR
// http://d.pr/n/1hi6m

int main()
{
	Ptr<ICalc> calc = CreateInstance();   // asInterface, CoCreateInstance(...); 
	cout << calc->add(1, 2) << endl;
	cout << calc->sub(1, 2) << endl;
}

#if 0
int main()
{
	ICalc* calc = CreateInstance();   // asInterface, CoCreateInstance(...); 
	calc->addRef();

	cout << calc->add(1, 2) << endl;
	cout << calc->sub(1, 2) << endl;

	calc->release();

	// delete calc; // �ɱ��? �̷��� �ϸ� ���� �ȵ˴ϴ�.
					// ����� ����� new�� ������ ������� delete ������ �ٸ� �� �ֽ��ϴ�.
					// �����Ϸ��� �ٸ���, ���̺귯���� ������ �ٸ��� �����Դϴ�.
					// ��� �ȿ��� new�� delete�� �����ؾ� �մϴ�.
}
#endif
