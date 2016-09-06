// �Լ��� ����6
// http://d.pr/n/qCOF
#include <algorithm>
#include <iostream>
using namespace std;

#include <functional>  // less<>, greater<>

// ���밪�� ���ϴ� �Լ� ��ü
template<typename T> struct absgreater {
	inline bool operator(T a, T b) { return abs(a) > abs(b); }
};

inline bool foo(T a, T b) { return abs(a) > abs(b); }

// �Լ� ��ü�� ���ϰ� ����ϴ� ���.
// ���� : �Լ��� ���ڷ� �ڵ� ������ ������ �� �ִ� ����
//   C++11, C#4.0, Java8, ObjC2
//  2008����� �����Ǿ���.(VS2010, gcc4.6)
// - 1980�� : C++ź��
// - 1998�� : 1�� ǥ�� Ȯ��, 2003�⿡ ������ - C++98/03, C++1.0
// - 2011�� : 2�� ǥ�� Ȯ��, 2014�⿡ ������ - C++11/14, C++2.0
// - 2017�� : 3�� ǥ�� Ȯ��(C++17)
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

	// �ӽ� ��ü�� ����� ����. : TYPE()
	sort(x, x + 10, greater<int>());
}