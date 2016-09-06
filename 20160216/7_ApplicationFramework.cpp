// 7_Application Framework
#include <iostream>
using namespace std;
// Libarary: ���α׷� ���߿� �ʿ��� ������ �����ϴ� ��
// Framework: ���� + �̸� ���ǵ� ���� �帧
//         "Template Method" ������ ����Ǵ� ��찡 ����.
//          => ��ü���� �帧�� ���̺귯�� �ȿ� �ΰ�, �� �ܰ踦 �����Լ�ȭ
//             �ؼ� �ڽ� Ŭ������ �������� �� �ֵ���...

#if 0
class CWinApp; // ���� ���� : ������ ���� ���̵� �����ʹ� ���� �� �ִ�.

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
// ����� �ڵ� �Դϴ�.
// �� ���̺귯���� ����ڴ� �Ʒ�ó�� ������ �մϴ�.
// ��Ģ 1. CWinApp�� �Ļ� Ŭ������ ������ �մϴ�.
// ��Ģ 2. InitInstance() �����Լ��� �������ؼ� �ʱ�ȭ �۾��� �����մϴ�.
// ��Ģ 3. ����ڰ� ���� Ŭ������ ���������� �Ѱ��� �����ؾ� �մϴ�.
#include <afxwin.h>  // �� �ȿ� main�� CWinApp�� �ֽ��ϴ�.

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