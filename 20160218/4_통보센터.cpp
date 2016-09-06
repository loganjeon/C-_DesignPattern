// 4_통보센터(Notification Center)

// 중재자(Mediator) 패턴
// : 복잡한 객체 간의 관계를 단순화 시켜주는 객체
//   도메인에 특화된 이식 불가능한 코드를 한 곳으로 모을 수 있다.

// C++ 에서 Callback 을 등록하는 2가지 모양
// 1. 인터페이스 기반으로 객체 등록 - 관찰자 패턴
// 2. 함수 포인터기반으로 함수 등록 - 통보 센터

// http://d.pr/n/lDEg
// 아이폰에서 모든 이벤트를 처리하는 통보 센터를 만들어 봅시다.
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;

class NotificationCenter
{
	typedef function<void()> HANDLER;

	map<string, vector<HANDLER>> notifi_map;
public:
	void addObserver(string key, HANDLER handler)
	{ 
		notifi_map[key].push_back(handler);
	}

	void postNotificationWithName(string key)
	{
		vector<HANDLER>& v = notifi_map[key];
		for (int i = 0; i < v.size(); ++i)
			v[i]();  // function은 ()로 호출합니다.
	}

	// Global / Local 통보 센터
	static NotificationCenter& defaultCenter()
	{
		static NotificationCenter instance;
		return instance;
	}
};

void foo() { cout << "foo" << endl; }
void goo(int n) { cout << "goo : " << n << endl; }

class Dialog { public: void close() { cout << "Dialog close" << endl; } };

// http://d.pr/n/1hArs
int main()
{
	Dialog dialog;

	NotificationCenter& center = NotificationCenter::defaultCenter();
	center.addObserver("LOWBATTERY", &foo);
	center.addObserver("LOWBATTERY", bind(&Dialog::close, &dialog));

	center.addObserver("MAIL", bind(&goo, 10));

	// 이제 배터리를 체크하는 모듈에서
	center.postNotificationWithName("LOWBATTERY");
}