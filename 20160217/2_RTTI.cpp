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

// 1. 개념 : 실행 시간에 p가 정말로 어떤 객체를 가르키는지 조사하는 것
// 2. 가상 함수 테이블로 관리되는 type_info를 사용하므로 가상 함수가 있어야
//    제대로 동작한다.
// 3. 가상 함수 테이블이 없으면 컴파일 시간에 p의 타입으로 type_info를 만드는
//    코드를 생성한다.

// http://d.pr/n/1iPAq

// http://d.pr/n/Y7jw
void foo(Animal* p)
{
	// dynamic_cast : 다운 캐스팅(부모 클래스 -> 자식 클래스)
	//                용도로 사용되는 캐스팅 입니다.
	// 동작 원리 : RTTI를 이용해서 타입을 조사한 후, 올바른 자식 타입이 아니면
	//             0을 리턴한다.
	
	// 방법 1.
	// 문제점 : 성능 저하가 있다.
	Dog* pDog = dynamic_cast<Dog*>(p);
	if (pDog)
		pDog->color = 10;

	// 방법 2.
	// 문제점 : 잘못된 다운 캐스팅을 감지할 수 없다.
	pDog = static_cast<Dog*>(p);
}


#if 0
void foo(Animal* p)
{
	// 클래스 이름을 알고 싶다면
	cout << typeid(*p).name() << endl;

	// 조사하는 방법 2.
	if (typeid(*p) == typeid(Dog))
	{
		//...
	}

	// 조사하는 방법 1.
	const type_info& t1 = typeid(*p);    // typeid(객체)
	const type_info& t2 = typeid(Dog);   // typeid(클래스)
	
	if (t1 == t2)
	{
		cout << "p는 Dog입니다." << endl;
	}
	else
	{
		cout << "p는 Animal입니다." << endl;
	}
}
#endif

int main()
{
	Animal a; foo(&a);
	Dog d;	  foo(&d);
}