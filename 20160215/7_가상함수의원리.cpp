// 7_가상함수의원리
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
// 함수 바인딩 : p->cry(); 어떤 함수로 연결할 것인가?
// 1. static binding : 컴파일 시간에 결정
//     : 포인터(레퍼런스)의 타입으로 결정
//   C/C++/C# 
//  빠르다, 비이성적

// 2. dynamic binding : 실행 시간에 결정
//     : 컴파일 시간에 p의 메모리를 조사하는 기계어 코드 생성
//       실행시간에 메모리를 조사후 호출
//   Java, Objective-C, virtual
//  상대적으로 느리다, 이성적
















