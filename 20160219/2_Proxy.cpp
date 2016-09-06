// 2_Proxy
// http://d.pr/n/xN1t

#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// http://d.pr/n/1cEKb
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