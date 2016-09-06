// 5_일반화 프로그래밍
// 참고 도서 : 일반적 프로그래밍과 STL

// C++ 라이브러리(STL)을 이해하려면 반드시 일반화를 이해해야 합니다.
// C++ : 객체 지향 + 함수형 + 일반적(Generic)
#include <iostream>
using namespace std;

// C의 문자열 검색

char* xstrchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
		++s;

	return *s == c ? s : 0;
}

// 1. 검색 구간의 일반화 : 부분 문자열 검색이 가능하게 하자.
//  검색 구간 - 반개 구간 [first, last)
char* xstrchr(char* first, char* last, char value)
{
	while (first != last && *first != value)
		++first;

	return first == last ? 0 : first;
}

// 2. 검색 대상 타입의 일반화 : Template 도입!
// template <typename T>
// -> 구간의 타입과 찾는 요소의 타입이 연관되어 있다.
//   double 배열에서 int를 찾을 수 없다.

// template <typename T1, typename T2>
// T1* xfind(T1* first, T1* last, T2 value)
// -> T* 라고 하면 진짜 포인터만 사용할 수 있다. 
//    스마트 포인터를 사용할 수 없다.
template <typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;

	return first;
}

// http://d.pr/n/1ggM5
#include <vector>
#include <list>

int main()
{
	list<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	cout << *xfind(v.begin(), v.end(), 20) << endl;
}




#if 0
int main()
{
	double x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double *p = xfind(x, x + 10, 3);
	if (p != x + 10)
		cout << *p << endl;
}
#endif



#if 0
int main()
{
	char s[] = "abcdefg";

	// char* p = xstrchr(s, 'c');
	
	char* p = xstrchr(s + 1, s + 4, 'c');
	if (p)
		cout << *p << endl;
}
#endif