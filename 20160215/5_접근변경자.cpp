// 5_접근변경자
// http://d.pr/n/7sXG
class Base
{
private: int a;
protected: int b;
public: int c;
};


class Derived : private Base  // 접근 변경자!
{};

int main()
{
	Base b; 
	Derived d; d.c = 10;
}