// 5_���ٺ�����
// http://d.pr/n/7sXG
class Base
{
private: int a;
protected: int b;
public: int c;
};


class Derived : private Base  // ���� ������!
{};

int main()
{
	Base b; 
	Derived d; d.c = 10;
}