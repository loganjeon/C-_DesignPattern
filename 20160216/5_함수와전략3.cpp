// 5_�Լ�������3
// �Լ� ��ü(functor)
// http://d.pr/n/1efjz
#include <iostream>
using namespace std;

// �Լ� ��ü(functor) : ȣ�� �����ڸ� �������Ͽ�, �Լ�ó�� ��밡���� ��ü
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