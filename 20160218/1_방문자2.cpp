// 1_방문자2
// C++ STL에서 컨테이너의 요소에 연산을 추가하는 방법.
// http://d.pr/n/1dVpE

// 반복자 + 함수 객체
#include <iostream>
#include <vector>
#include <algorithm>  // for_each
using namespace std;

struct twice_functor
{
	void operator()(int& n) { n *= 2; }
};

int main()
{
	vector<int> s;
	s.push_back(10);
	s.push_back(20);
	s.push_back(30);

	for_each(s.begin(), s.end(), [](int& n) {
		n *= 2;
	});

	for_each(s.begin(), s.end(), [](int n) {
		cout << n << endl;
	});
}
