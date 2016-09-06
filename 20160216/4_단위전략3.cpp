#include <iostream>
#include <string>
using namespace std;

// http://d.pr/n/19q4K
// basic_string<> �� ����å���� ����� ��å Ŭ������ ��������.
class my_traits : public char_traits<char>
{
public:
	// ���ڿ� �� ��å �Լ�
	static bool compare(const char* a, const char* b, size_t sz)
	{ return strcmpi(a, b); }
};

typedef basic_string<char, my_traits> idstring;

int main()
{
	idstring s1 = "abcd";
	idstring s2 = "ABCD";

	if (s1 == s2)
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}

#if 0
#include <iostream>
#include <vector>
using namespace std;

#include "tbb/cache_aligned_allocator.h"
using namespace tbb;

int main()
{
	vector<int, cache_aligned_allocator<int>> v;
}
#endif