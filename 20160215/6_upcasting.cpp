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

// 핵심: A와 B를 묶고 싶다면 => 공통의 부모를 만들어라
// http://d.pr/n/17pxi
int main()
{
	vector<Dog*> v;    // Dog만 담을 수 있다.
	vector<Animal*> v; // 모든 동물을 담을 수 있다.

	Animal a;
	Dog d;       foo(&d);
				// Upcasting : 자식 객체의 주소를 
	            //             부모의 포인터로 가르킬 수 있다.
				// 주의 : public 상속일때만 가능하다.
}