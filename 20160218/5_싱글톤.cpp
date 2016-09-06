// 5_�̱���
#include <iostream>
using namespace std;
// �ǵ� : ���� �Ѱ��� ��ü�� ���� �� �ְ�, ������ �������
//        ��ü�� ���� �� �ְ� �ϴ� ����.
class Cursor
{
private:
	Cursor() {} // ��Ģ 1. private ������

	// ��Ģ 3. ����/���� ����
	//  �ٽ� : ���� �Ѵ�!! ������ ����.
	//  ���� ���� ����� C++11���� �������� ���ԵǾ����ϴ�.
	//  "delete function"
	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete;

public:
	// ��Ģ 2. ���� �Ѱ��� �����, �����ϴ� ���� ��� �Լ�
	// ���̾�� �̱��� - Effective C++���� ���ȵǾ���.
	static Cursor& getInstance()
	{
		static Cursor instance;	
		return instance;
	}
};

int main()
{
	Cursor& instance = Cursor::getInstance();

	// Cursor instance2 = instance;  // ���� ������!!!!
}