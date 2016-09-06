// 2_Proxy2
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// 서비스의 개발자는 클라이언트에서 프로토콜을 몰라도 서비스를 이용할 수 있도록
// 서버의 요소를 대신할 수 있는 클래스를 제공해야 합니다.
// Remote Proxy
// http://d.pr/n/17wYG

// Proxy는 완벽하게 서버를 대신할 수 있어야 합니다.
// 서버와 완전히 동일한 함수를 제공하기로 약속되어야 합니다.
// => 인터페이스
struct ICalc
{
	virtual void add(int, int) = 0;
	virtual void sub(int, int) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int handle;
public:
	Calc() { handle = IoFindServer("CalcServer"); }

	int add(int a, int b) { return IoSendServer(handle, 1, a, b); }
	int sub(int a, int b) { return IoSendServer(handle, 2, a, b); }
};

int main()
{
	Calc* calc = new Calc;

	cout << calc->add(1, 2) << endl;
	cout << calc->sub(1, 2) << endl;
}



#if 0
int main()
{
	int handle = IoFindServer("CalcServer");
	cout << "서버 번호: " << handle << endl;

	while (1)
	{
		cout << IoSendServer(handle, 1, 1, 2) << endl;
		getchar();

		cout << IoSendServer(handle, 2, 1, 2) << endl;
		getchar();
	}
}
#endif