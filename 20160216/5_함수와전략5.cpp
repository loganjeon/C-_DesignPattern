// 5_함수와전략5


inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Greater {
	inline bool operator()(int a, int b) { return a < b; }
};

struct Less {
	inline bool operator()(int a, int b) { return a < b; }
};

#include <iostream>
using namespace std;

#include <algorithm> // 정책이 변경 가능한 sort가 이미 있습니다.

// http://d.pr/n/12cM6
int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	
	// 2. 정책으로 함수 객체를 사용할 때
	// 장점: 정책이 인라인 치환되므로 빠르다.
	// 단점: 정책을 교체한 횟수 만큼의 sort() 기계어 코드 생성
	Less less; Greater greater;
	sort(x, x + 10, less);     // sort(int*, int*, Less)인 함수 생성
	sort(x, x + 10, greater);  // sort(int*, int*, Greater)인 함수 생성

	// 1. 정책으로 일반 함수를 사용할 때
	// 장점: 정책을 여러번 교체해도 sort()의 기계어는 하나이다.
	// 단점: 정책이 인라인 치환이 불가능하므로 성능 저하가 있다.
	sort(x, x + 10, cmp1);  // sort(int*, int*, bool(*)(int,int))인 함수 생성
	sort(x, x + 10, cmp2);  // 이미 생성된 함수를 사용한다.

	for (int i = 0; i < 10; ++i)
		cout << x[i] << endl;
}
