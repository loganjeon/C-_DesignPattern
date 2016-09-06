// 7_�����Լ��ǿ���
#include <iostream>
using namespace std;

class Animal
{
public:
	void cry() { cout << "Animal cry" << endl; } // 1
};

class Dog : public Animal
{
public:
	void cry() { cout << "Dog cry" << endl; }    // 2
};

int main()
{
	Animal a;   a.cry();
	Dog d;		d.cry();

	Animal* p = &d;

	int n;
	cin >> n;
	if (n == 0)
		p = &a;


	p->cry();
}

// http://d.pr/n/1jzkB
// �Լ� ���ε� : p->cry(); � �Լ��� ������ ���ΰ�?
// 1. static binding : ������ �ð��� ����
//     : ������(���۷���)�� Ÿ������ ����
//   C/C++/C# 
//  ������, ���̼���

// 2. dynamic binding : ���� �ð��� ����
//     : ������ �ð��� p�� �޸𸮸� �����ϴ� ���� �ڵ� ����
//       ����ð��� �޸𸮸� ������ ȣ��
//   Java, Objective-C, virtual
//  ��������� ������, �̼���
















