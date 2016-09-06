// 7_Application Framework
#include <iostream>
using namespace std;
// Libarary: 프로그램 개발에 필요한 도구를 제공하는 것
// Framework: 도구 + 미리 정의된 실행 흐름
//         "Template Method" 패턴이 적용되는 경우가 많다.
//          => 전체적인 흐름은 라이브러리 안에 두고, 각 단계를 가상함수화
//             해서 자식 클래스로 재정의할 수 있도록...

#if 0
class CWinApp; // 전방 선언 : 완전한 선언 없이도 포인터는 만들 수 있다.

CWinApp* g_app;
class CWinApp
{
public:
	CWinApp() { g_app = this; }
	virtual bool InitInstance()  { return false; }
	virtual int ExitInstance()   { return 0; }
	virtual int Run()            { return 0; }
};

CWinApp* AfxGetApp() { return g_app; }

int main()
{
	CWinApp* pApp = AfxGetApp();
	if (pApp->InitInstance())
		pApp->Run();
	pApp->ExitInstance();
}
#endif

// http://d.pr/n/1kzqA
//--------------------------------
// 사용자 코드 입니다.
// 위 라이브러리의 사용자는 아래처럼 만들어야 합니다.
// 규칙 1. CWinApp의 파생 클래스를 만들어야 합니다.
// 규칙 2. InitInstance() 가상함수를 재정의해서 초기화 작업을 수행합니다.
// 규칙 3. 사용자가 만든 클래스를 전역적으로 한개를 생성해야 합니다.
#include <afxwin.h>  // 이 안에 main과 CWinApp이 있습니다.

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		// cout << "Hello MFC" << endl;
		AfxMessageBox(L"Hello MFC");
		return false;
	}

	virtual int ExitInstance()
	{
		// cout << "GoodBye MFC" << endl;
		AfxMessageBox(L"Bye MFC");
		return 0;
	}
};


CMyApp theApp;