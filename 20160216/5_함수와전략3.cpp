// 5_함수와전략3
// 함수 객체(functor)
// http://d.pr/n/1efjz
#include <iostream>
using namespace std;

// 함수 객체(functor) : 호출 연산자를 재정의하여, 함수처럼 사용가능한 객체
struct Plus
{
	int operator()(int a, int b) {
		return a + b;
	}
};

int main()
{
	Plus plus;

	int n = plus(10, 20);
	cout << n << endl;
}