// 5_접근변경자2
#include <iostream>
using namespace std;

// list가 이미 있습니다.
#include <list>

// 그런데 사용자가 stack을 요구합니다.
// 1. stack을 다시 만들어주자.
// 2. list를 한쪽으로 사용하면 stack이다. list를 재사용하자.
#if 0
template <typename T> class stack : private list<T>
{
public:
	inline void push(const T& a) { push_back(a); }  // 부모의 함수를 재사용
	inline void pop()			 { pop_back(); }
	inline T&   top()            { return back(); }
};
#endif

// http://d.pr/n/2J5A
// Adapter Pattern : 기존 클래스의 인터페이스(함수 이름) 변경해서
//                   사용자가 요구하는 클래스처럼 보이게 하는 패턴.

// 라이브러리의 설계자는 사용자가 클래스를 사용하기 쉽게 만드는 것도
// 중요하지만, 잘못 사용하기 어렵게 만드는 것도 중요하다.

// private 상속 : 부모 클래스로부터 구현은 물려 받지만
//                               (자식이 내부적으로 사용하지만,)
//                인터페이스는 물려 받지 않겠다.
//                               (부모 함수를 외부로 노출하지 않겠다.)

// S/W 재사용은 상속과 포함이 있다. => 포함이 좋을때가 많다.
// C++ 표준 stack은 아래와 유사합니다. -> "stack adapter"
#include <stack>
#include <deque>
template <typename T, typename C=deque<T>> class xstack
{
	C st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline void pop()            { st.pop_back(); }
	inline T& top()              { return st.back(); }
};

#include <vector>

int main()
{
	stack<int> s2;

	stack<int, vector<int>> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);

	// s1.push_front(10);
	
	cout << s1.top() << endl;
}


