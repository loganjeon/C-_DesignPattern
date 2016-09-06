
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
// decay �� : ������ ���޵� ��, �Լ��� �迭�� �ǹ̰� �޶�����.
// - ���� : &, sizeof, reference
// �迭 : �迭�� ù��° ������ ���� �ּ�
// �Լ� : �Լ��� �ּ�

int main()
{
	int  n = 0;			foo(n);
	int* p = 0;         foo(p);
	
	int x[10];

	foo(x);
	foo(main);
}
#endif