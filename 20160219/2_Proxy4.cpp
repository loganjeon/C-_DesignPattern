// 2_Proxy4
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// 이제 서버 개발자에게서 2개의 파일을 받아야 합니다.
// 1. ICalc.h : 인터페이스 헤더
// 2. CalcProxy.dll : Proxy 클래스 라이브러리
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

	// delete calc; // 될까요? 이렇게 하면 절대 안됩니다.
					// 모듈을 만드는 new의 버전과 사용자의 delete 버전은 다를 수 있습니다.
					// 컴파일러가 다르면, 라이브러리의 버전이 다르기 때문입니다.
					// 모듈 안에서 new와 delete를 수행해야 합니다.
}
#endif
