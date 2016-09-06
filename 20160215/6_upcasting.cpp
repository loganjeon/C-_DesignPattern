// 6_upcasting

#include <iostream>
using namespace std;

class Animal
{
public:
	void cry() { cout << "Animal cry" << endl; }
};

class Dog : public Animal
{
};

void foo(Animal* p)
{
	p->cry();
}

#include <vector>

// �ٽ�: A�� B�� ���� �ʹٸ� => ������ �θ� ������
// http://d.pr/n/17pxi
int main()
{
	vector<Dog*> v;    // Dog�� ���� �� �ִ�.
	vector<Animal*> v; // ��� ������ ���� �� �ִ�.

	Animal a;
	Dog d;       foo(&d);
				// Upcasting : �ڽ� ��ü�� �ּҸ� 
	            //             �θ��� �����ͷ� ����ų �� �ִ�.
				// ���� : public ����϶��� �����ϴ�.
}