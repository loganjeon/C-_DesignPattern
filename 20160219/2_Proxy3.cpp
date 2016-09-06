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

// Proxy는 결국 서버 제작자가 만들게 됩니다.
//---------------------------------------------

int main()
{
	// 아래 처럼 만들면 Proxy와 사용자 사이에 강한 결합이 형성됩니다.
	// => Proxy가 업데이트 되면 클라이언트 코드를 다시 빌드해야 합니다.

	// ICalc* calc = new Calc;
	// Calc* calc = new Calc;

	cout << calc->add(1, 2) << endl;
	cout << calc->sub(1, 2) << endl;
}
