// 1_�湮��2
// C++ STL���� �����̳��� ��ҿ� ������ �߰��ϴ� ���.
// http://d.pr/n/1dVpE

// �ݺ��� + �Լ� ��ü
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
