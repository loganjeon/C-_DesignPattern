// 2_RTTI : Run Time Type Inforamtion
#include <iostream>
using namespace std;

class Animal
{
public:
	virtual ~Animal() {}
};

class Dog : public Animal
{
public:
	int color;
};

// 1. ���� : ���� �ð��� p�� ������ � ��ü�� ����Ű���� �����ϴ� ��
// 2. ���� �Լ� ���̺�� �����Ǵ� type_info�� ����ϹǷ� ���� �Լ��� �־��
//    ����� �����Ѵ�.
// 3. ���� �Լ� ���̺��� ������ ������ �ð��� p�� Ÿ������ type_info�� �����
//    �ڵ带 �����Ѵ�.

// http://d.pr/n/1iPAq

// http://d.pr/n/Y7jw
void foo(Animal* p)
{
	// dynamic_cast : �ٿ� ĳ����(�θ� Ŭ���� -> �ڽ� Ŭ����)
	//                �뵵�� ���Ǵ� ĳ���� �Դϴ�.
	// ���� ���� : RTTI�� �̿��ؼ� Ÿ���� ������ ��, �ùٸ� �ڽ� Ÿ���� �ƴϸ�
	//             0�� �����Ѵ�.
	
	// ��� 1.
	// ������ : ���� ���ϰ� �ִ�.
	Dog* pDog = dynamic_cast<Dog*>(p);
	if (pDog)
		pDog->color = 10;

	// ��� 2.
	// ������ : �߸��� �ٿ� ĳ������ ������ �� ����.
	pDog = static_cast<Dog*>(p);
}


#if 0
void foo(Animal* p)
{
	// Ŭ���� �̸��� �˰� �ʹٸ�
	cout << typeid(*p).name() << endl;

	// �����ϴ� ��� 2.
	if (typeid(*p) == typeid(Dog))
	{
		//...
	}

	// �����ϴ� ��� 1.
	const type_info& t1 = typeid(*p);    // typeid(��ü)
	const type_info& t2 = typeid(Dog);   // typeid(Ŭ����)
	
	if (t1 == t2)
	{
		cout << "p�� Dog�Դϴ�." << endl;
	}
	else
	{
		cout << "p�� Animal�Դϴ�." << endl;
	}
}
#endif

int main()
{
	Animal a; foo(&a);
	Dog d;	  foo(&d);
}