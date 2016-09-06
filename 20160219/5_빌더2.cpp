#include <iostream>
using namespace std;

// 생성자의 인자가 많을 때

// 방법 1. Telescoping Constructor Pattern (점층적 생성자 패턴)
// http://d.pr/n/1718h
class User
{
public:
	User(string id, int level, int exp, int gold, int cash)
		: id_(id), level_(level), exp_(exp), gold_(gold),cash_(cash) {}

	// 생성자 위임 : C++11 부터 가능하다.
	User(string id, int level, int exp, int gold)
		: User(id, level, exp, gold, 0) {}

	User(string id, int level, int exp)
		: User(id, level, exp, 0, 0) {}

	User(string id, int level)
		: User(id, level, 0, 0, 0) {}
private:
	const string id_;
	int level_;
	int exp_;
	int gold_;
	int cash_;
};

int main()
{
	// 객체를 생성할 때는 설정하려는 인자의 개수에 맞는 생성자를 골라서 호출하면 된다.
	// 문제점
	// 1. 인자 수가 늘어남에 따라 코드 작성이 번거롭다.
	// 2. 가독성이 좋지 않다.
	// 3. 같은 타입의 인자의 순서를 뒤집어도 컴파일러는 알 수 없다.
	User u1 = new User("chansik.yun", 10, 1000, 50, 0);
	User u2 = new User("chansik.yun", 10, 1000, 50);
}