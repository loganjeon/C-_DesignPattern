// 3_ĳ����
#include <iostream>
using namespace std;

// http://d.pr/n/18wbh
// 1. C++�� 4���� ĳ������ �����ϰ� �ִ�.
//  a. static_cast : void* �� ������ �ִ� ĳ������ ����Ѵ�.
//  b. reinterpret_cast : �޸� ���ؼ�, ���� ����
//  c. const_cast : ��ü(����)�� �����, �ֹ߼��� �����ϴ� �� ���ȴ�.
//  d. dynamic_cast

int main()
{
	volatile int c = 10;

	// int* p = (int*)&c;
	// int* p = (int*)&c;
	int* p = const_cast<int*>(&c);
	*p = 20;

	cout << *p << endl;
	cout << c << endl;

}



#if 0
int main()
{
	// int* p = (int*)malloc(sizeof(100));
	int *p = static_cast<int*>(malloc(sizeof(100)));

	int n = 0;
	// double* p2 = static_cast<double*>(&n);
	// double* p2 = (double*)(&n);
	double* p2 = reinterpret_cast<double*>(&n);
}
#endif



// 2. C�� ĳ������ �ʹ� �����ϴ�.(���̼���, unresonable)