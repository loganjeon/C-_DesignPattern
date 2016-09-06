#include <iostream>
using namespace std;

// 생성자의 인자가 많을 때
// 방법 2. Beans 생성 패턴
// : 기본 생성자를 호출하여 객체를 만든 후, 세터를 호출하려 모든 필드의 값을 채운다.
class User
{
public:
	User() {}

	void setId(string v) {
		id_ = v;
	}
	void setLevel(int v) {
		level_ = v;
	}
	void setExp(int v) {
		exp_ = v;
	}
	void setGold(int v) {
		gold_ = v;
	}
	void setCash(int v) {
		cash_ = v;
	}
private:
	string id_;
	int level_;
	int exp_;
	int gold_;
	int cash_;
};

// http://d.pr/n/1943U
// 장점: 객체를 생성하기 쉽고, 읽기도 좋다.
// 단점: 1. 필수 필드와 상수 필드를 표현할 수 없다.
//       2. 1회의 함수 호출로 인해 객체를 생성할 수 없으므로, 객체 일관성이 쉽게 깨진다.
//          추가적으로 고려해야 되는 사항이 많다. - 스레드 안전성
int main()
{
	User u;
	u.setId("chansik.yun");
	u.setLevel(10);
	u.setExp(300);
	u.setGold(1000);
	u.setCash(50);
}
