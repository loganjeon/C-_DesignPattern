
// http://d.pr/n/7BPo
#include <iostream>
using namespace std;

template <typename T>
void foo(T& a)
{
	cout << typeid(T).name() << endl;
}

template <typename T>
void compare(T& a, T& b)
{
	//...
}

int main()
{
	compare("aaa", "bbbb");
}


#if 0
// decay 룰 : 값으로 전달될 때, 함수와 배열은 의미가 달라진다.
// - 예외 : &, sizeof, reference
// 배열 : 배열의 첫번째 원소의 시작 주소
// 함수 : 함수의 주소

int main()
{
	int  n = 0;			foo(n);
	int* p = 0;         foo(p);
	
	int x[10];

	foo(x);
	foo(main);
}
#endif