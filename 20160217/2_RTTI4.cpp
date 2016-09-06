// 2_RTTI4
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
// http://d.pr/n/BVT3

// �� ��Ģ�� ��ũ��ȭ �մϴ�.
#define DECLARE_DYNAMIC(classname)								\
	public:														\
		static CRuntimeClass class##classname;					\
		virtual CRuntimeClass* GetRuntimeClass();

#define IMPLEMENT_DYNAMIC(classname)									\
	CRuntimeClass classname::class##classname = { #classname };			\
	CRuntimeClass* classname::GetRuntimeClass()							\
	{ return &class##classname; }

// Ŭ���� �̸����� static ������ CRuntimeClass�� ��� ��ũ��
#define RUNTIME_CLASS(classname)	&(classname::class##classname)

class Animal
{
	DECLARE_DYNAMIC(Animal)
};
IMPLEMENT_DYNAMIC(Animal)

class Dog : public Animal
{
	DECLARE_DYNAMIC(Dog)
};
IMPLEMENT_DYNAMIC(Dog)


void foo(Animal* p)
{
	if (p->GetRuntimeClass() == RUNTIME_CLASS(Dog))
		cout << "p�� Dog�Դϴ�." << endl;
}

int main()
{
	Dog d; foo(&d);
}


// http://d.pr/n/Jqob