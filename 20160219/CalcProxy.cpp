// CalcProxy.cpp
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

#include "ICalc.h"

class Calc : public ICalc
{
	int handle;
public:
	Calc() { handle = IoFindServer("CalcServer"); }
	~Calc() { cout << "Calc �ı�" << endl; }

	int add(int a, int b) { return IoSendServer(handle, 1, a, b); }
	int sub(int a, int b) { return IoSendServer(handle, 2, a, b); }
};

// ���� ���̺귯��(DLL, so) �ȿ��� Proxy�� ����� �Լ��� ���� �����ؾ� �մϴ�.
extern "C"
__declspec(dllexport)
ICalc* CreateCalc() { return new Calc; }

// cl CalcProxy.cpp /LD /link user32.lib gdi32.lib kernel32.lib