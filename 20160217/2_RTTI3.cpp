// 2_RTTI3
// RTTI�� �ٽ��� type_info �Դϴ�. �ᱹ�� ���� ��� ������ �����մϴ�.
#include <string>
#include <iostream>
using namespace std;

// type_info ��Ȱ
struct CRuntimeClass
{
	string name;
	string author;
	string version;
};

// ��� Ŭ������ �Ʒ� ��Ģ�� ���Ѿ� �մϴ�.
// 1. ��� Ŭ�������� ���� ��� ������ CRuntimeClass �� �־�� �մϴ�.
// 2. ���� �̸��� "classŬ�����̸�" ���� �Ѵ�. ex)classDog, classAnimal
// 3. ���� ������ �����ϴ� ���� �Լ��� GetRuntimeClass()�� �־�� �մϴ�.

class Animal
{
public:
	static CRuntimeClass classAnimal;
	virtual CRuntimeClass* GetRuntimeClass() 
	{ return &classAnimal; }
};

CRuntimeClass Animal::classAnimal = { "Animal" };

class Dog : public Animal
{
public:
	static CRuntimeClass classDog;
	virtual CRuntimeClass* GetRuntimeClass()
	{ return &classDog; }
};

CRuntimeClass Dog::classDog = { "Dog" };

// http://d.pr/n/19c0D
void foo(Animal* p)
{
	if (p->GetRuntimeClass() == &Dog::classDog)
		cout << "p�� Dog�Դϴ�." << endl;
}

int main()
{
	Dog d; foo(&d);
}