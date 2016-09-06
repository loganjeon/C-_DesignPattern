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
	~Calc() { cout << "Calc 파괴" << endl; }

	int add(int a, int b) { return IoSendServer(handle, 1, a, b); }
	int sub(int a, int b) { return IoSendServer(handle, 2, a, b); }
};

// 동작 라이브러리(DLL, so) 안에서 Proxy를 만드는 함수를 같이 제공해야 합니다.
extern "C"
__declspec(dllexport)
ICalc* CreateCalc() { return new Calc; }

// cl CalcProxy.cpp /LD /link user32.lib gdi32.lib kernel32.lib