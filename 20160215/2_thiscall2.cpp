// 2_thiscall
// http://d.pr/n/14ast
#include <iostream>
using namespace std;

class Sample
{
	int data;
public:
	void f1()  // void f1(Sample* this)
	{ cout << "f1" << endl; }

	int f2() 
	{
		cout << "f2" << endl;
		return 0;
	}

	// 아래 함수는 왜 만들었을까요?
	int call_f3() {
		return this ? f3() : NULL;
	}


protected:
	int f3()
	{
		cout << "f3" << endl;
		return data;  // return this->data;
	}

};

int main()
{
	Sample* p = NULL; // 메모리 할당을 하다가 0이 나왔다고 가정합니다.

	p->f1();  // f1(p); -> f1(NULL);
	p->f2();
	// p->f3();

}