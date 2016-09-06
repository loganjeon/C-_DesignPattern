// 함수와 전략6
// http://d.pr/n/qCOF
#include <algorithm>
#include <iostream>
using namespace std;

#include <functional>  // less<>, greater<>

// 절대값을 비교하는 함수 객체
template<typename T> struct absgreater {
	inline bool operator(T a, T b) { return abs(a) > abs(b); }
};

inline bool foo(T a, T b) { return abs(a) > abs(b); }

// 함수 객체를 편리하게 사용하는 방법.
// 람다 : 함수의 인자로 코드 조각을 전달할 수 있는 문법
//   C++11, C#4.0, Java8, ObjC2
//  2008년부터 지원되었다.(VS2010, gcc4.6)
// - 1980년 : C++탄생
// - 1998년 : 1차 표준 확정, 2003년에 수정판 - C++98/03, C++1.0
// - 2011년 : 2차 표준 확정, 2014년에 수정판 - C++11/14, C++2.0
// - 2017년 : 3차 표준 확정(C++17)
int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	sort(x, x + 10, [](int a, int b) {
		return abs(a) > abs(b);
	});

	absgreater<int> ag;
	sort(x, x + 10, ag);

	sort(x, x + 10, absgreater<int>());

	less<int> l; 
	greater<int> g;
	sort(x, x + 10, l);
	sort(x, x + 10, g);

	// 임시 객체를 사용한 문법. : TYPE()
	sort(x, x + 10, greater<int>());
}