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

	// �Ʒ� �Լ��� �� ����������?
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
	Sample* p = NULL; // �޸� �Ҵ��� �ϴٰ� 0�� ���Դٰ� �����մϴ�.

	p->f1();  // f1(p); -> f1(NULL);
	p->f2();
	// p->f3();

}