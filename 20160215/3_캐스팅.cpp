// 3_캐스팅
#include <iostream>
using namespace std;

// http://d.pr/n/18wbh
// 1. C++은 4개의 캐스팅을 제공하고 있다.
//  a. static_cast : void* 나 연관성 있는 캐스팅을 허용한다.
//  b. reinterpret_cast : 메모리 재해석, 거의 성공
//  c. const_cast : 객체(변수)의 상수성, 휘발성을 제거하는 데 사용된다.
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



// 2. C의 캐스팅은 너무 위험하다.(비이성적, unresonable)