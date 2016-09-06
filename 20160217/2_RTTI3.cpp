// 2_RTTI3
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
		cout << "p는 Dog입니다." << endl;
}

int main()
{
	Dog d; foo(&d);
}