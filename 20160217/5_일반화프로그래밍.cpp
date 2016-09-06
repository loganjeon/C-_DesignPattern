// 5_�Ϲ�ȭ ���α׷���
// ���� ���� : �Ϲ��� ���α׷��ְ� STL

// C++ ���̺귯��(STL)�� �����Ϸ��� �ݵ�� �Ϲ�ȭ�� �����ؾ� �մϴ�.
// C++ : ��ü ���� + �Լ��� + �Ϲ���(Generic)
#include <iostream>
using namespace std;

// C�� ���ڿ� �˻�

char* xstrchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
		++s;

	return *s == c ? s : 0;
}

// 1. �˻� ������ �Ϲ�ȭ : �κ� ���ڿ� �˻��� �����ϰ� ����.
//  �˻� ���� - �ݰ� ���� [first, last)
char* xstrchr(char* first, char* last, char value)
{
	while (first != last && *first != value)
		++first;

	return first == last ? 0 : first;
}

// 2. �˻� ��� Ÿ���� �Ϲ�ȭ : Template ����!
// template <typename T>
// -> ������ Ÿ�԰� ã�� ����� Ÿ���� �����Ǿ� �ִ�.
//   double �迭���� int�� ã�� �� ����.

// template <typename T1, typename T2>
// T1* xfind(T1* first, T1* last, T2 value)
// -> T* ��� �ϸ� ��¥ �����͸� ����� �� �ִ�. 
//    ����Ʈ �����͸� ����� �� ����.
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