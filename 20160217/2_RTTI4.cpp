// 2_RTTI4
// RTTI의 핵심은 type_info 입니다. 결국은 정적 멤버 변수와 유사합니다.
#include <string>
#include <iostream>
using namespace std;

// type_info 역활
struct CRuntimeClass
{
	string name;
	string author;
	string version;
};

// 모든 클래스는 아래 규칙을 지켜야 합니다.
// 1. 모든 클래스에는 정적 멤버 변수인 CRuntimeClass 가 있어야 합니다.
// 2. 변수 이름을 "class클래스이름" 으로 한다. ex)classDog, classAnimal
// 3. 정적 변수를 리턴하는 가상 함수인 GetRuntimeClass()가 있어야 합니다.
// http://d.pr/n/BVT3

// 위 규칙을 매크로화 합니다.
#define DECLARE_DYNAMIC(classname)								\
	public:														\
		static CRuntimeClass class##classname;					\
		virtual CRuntimeClass* GetRuntimeClass();

#define IMPLEMENT_DYNAMIC(classname)									\
	CRuntimeClass classname::class##classname = { #classname };			\
	CRuntimeClass* classname::GetRuntimeClass()							\
	{ return &class##classname; }

// 클래스 이름으로 static 변수인 CRuntimeClass를 얻는 매크로
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
		cout << "p는 Dog입니다." << endl;
}

int main()
{
	Dog d; foo(&d);
}


// http://d.pr/n/Jqob