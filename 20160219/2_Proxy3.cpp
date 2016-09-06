// 2_Proxy3
// http://d.pr/n/1hqYz
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;


// CalcProxy.dll -> CalcProxy.cpp
class Calc : public ICalc
{
	int handle;
public:
	Calc() { handle = IoFindServer("CalcServer"); }

	int add(int a, int b) { return IoSendServer(handle, 1, a, b); }
	int sub(int a, int b) { return IoSendServer(handle, 2, a, b); }
};

// Proxy�� �ᱹ ���� �����ڰ� ����� �˴ϴ�.
//---------------------------------------------

int main()
{
	// �Ʒ� ó�� ����� Proxy�� ����� ���̿� ���� ������ �����˴ϴ�.
	// => Proxy�� ������Ʈ �Ǹ� Ŭ���̾�Ʈ �ڵ带 �ٽ� �����ؾ� �մϴ�.

	// ICalc* calc = new Calc;
	// Calc* calc = new Calc;

	cout << calc->add(1, 2) << endl;
	cout << calc->sub(1, 2) << endl;
}
