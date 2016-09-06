// SampleGraph.cpp

#include "IObserver.h"

#include <iostream>
using namespace std;

class SampleGraph : public IObserver
{
public:
	void onUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "********* Sample Graph *********" << endl;
		for (int i = 0; i < 5; i++)
			cout << i << " : " << data[i] << endl;
	}
};


// SampleGraph 라는 이름은 현재 DLL을 만드는 사람만 알고 있습니다.
// .exe 에서는 절대 이름을 알 수 없습니다.
// 그래서, DLL의 설계자는 자신이 만든 클래스의 객체를 생성할 수 있는
// 방법을 제공해 주어야 합니다.

// 함수 하나를 약속합니다.
extern "C"					// 컴파일 할 때 함수 이름을 변경하지 말라는 것
__declspec(dllexport)       // 윈도우에서 DLL을 만들 때 필요.
IObserver* CreateGraph()
{
	return new SampleGraph;
}

// /LD : DLL 만드는 옵션
// cl SampleGraph.cpp /LD

// D:\plugin 폴더를 만드세요. SampleGraph.dll을 복사해 넣어두세요.