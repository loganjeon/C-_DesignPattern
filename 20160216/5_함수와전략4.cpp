// 5_함수와전략4
#include <iostream>
using namespace std;

// 1. 함수는 자신만의 타입이 없습니다.
//  : 시그니처가 동일한 모든 함수는 같은 타입이다.

// 2. 함수 객체는 자신만의 타입이 있다.
//  : 시그니처가 동일해도 모든 함수객체는 다른 타입이다.
struct Greater
{
	inline bool operator()(int a, int b) { return a < b; }
};

struct Less
{
	inline bool operator()(int a, int b) { return a > b; }
};

// http://d.pr/n/16sXY
// void sort(int* x, int n, bool(*cmp)(int, int))
// void sort(int* x, int n, Greater cmp)
// void sort(int* x, int n, Less cmp)
template <typename T>
void sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}



inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

int main()
{
	Less less; Greater greater;

	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	sort(x, 10, less);
	sort(x, 10, greater);
	sort(x, 10, cmp1);

	for (int i = 0; i < 10; i++)
		cout << x[i] << endl;
}



