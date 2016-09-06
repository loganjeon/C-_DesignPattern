#include <iostream>
using namespace std;

// �������� ���ڰ� ���� ��

// ��� 1. Telescoping Constructor Pattern (������ ������ ����)
// http://d.pr/n/1718h
class User
{
public:
	User(string id, int level, int exp, int gold, int cash)
		: id_(id), level_(level), exp_(exp), gold_(gold),cash_(cash) {}

	// ������ ���� : C++11 ���� �����ϴ�.
	User(string id, int level, int exp, int gold)
		: User(id, level, exp, gold, 0) {}

	User(string id, int level, int exp)
		: User(id, level, exp, 0, 0) {}

	User(string id, int level)
		: User(id, level, 0, 0, 0) {}
private:
	const string id_;
	int level_;
	int exp_;
	int gold_;
	int cash_;
};

int main()
{
	// ��ü�� ������ ���� �����Ϸ��� ������ ������ �´� �����ڸ� ��� ȣ���ϸ� �ȴ�.
	// ������
	// 1. ���� ���� �þ�� ���� �ڵ� �ۼ��� ���ŷӴ�.
	// 2. �������� ���� �ʴ�.
	// 3. ���� Ÿ���� ������ ������ ����� �����Ϸ��� �� �� ����.
	User u1 = new User("chansik.yun", 10, 1000, 50, 0);
	User u2 = new User("chansik.yun", 10, 1000, 50);
}