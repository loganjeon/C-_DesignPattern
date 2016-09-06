// 5_싱글톤
#include <iostream>
using namespace std;
// 의도 : 오직 한개의 객체만 만들 수 있고, 동일한 방법으로
//        객체를 얻을 수 있게 하는 패턴.
class Cursor
{
private:
	Cursor() {} // 규칙 1. private 생성자

	// 규칙 3. 복사/대입 금지
	//  핵심 : 선언만 한다!! 구현이 없다.
	//  복사 금지 기법은 C++11에서 문법으로 도입되었습니다.
	//  "delete function"
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

public:
	// 규칙 2. 오직 한개만 만들고, 제공하는 정적 멤버 함수
	// 마이어스의 싱글톤 - Effective C++에서 제안되었다.
	static Cursor& getInstance()
	{
		static Cursor instance;	
		return instance;
	}
};

int main()
{
	Cursor& instance = Cursor::getInstance();

	// Cursor instance2 = instance;  // 복사 생성자!!!!
}