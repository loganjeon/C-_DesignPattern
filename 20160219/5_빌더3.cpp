#include <iostream>
using namespace std;

// �������� ���ڰ� ���� ��
// ��� 2. Beans ���� ����
// : �⺻ �����ڸ� ȣ���Ͽ� ��ü�� ���� ��, ���͸� ȣ���Ϸ� ��� �ʵ��� ���� ä���.
class User
{
public:
	User() {}

	void setId(string v) {
		id_ = v;
	}
	void setLevel(int v) {
		level_ = v;
	}
	void setExp(int v) {
		exp_ = v;
	}
	void setGold(int v) {
		gold_ = v;
	}
	void setCash(int v) {
		cash_ = v;
	}
private:
	string id_;
	int level_;
	int exp_;
	int gold_;
	int cash_;
};

// http://d.pr/n/1943U
// ����: ��ü�� �����ϱ� ����, �б⵵ ����.
// ����: 1. �ʼ� �ʵ�� ��� �ʵ带 ǥ���� �� ����.
//       2. 1ȸ�� �Լ� ȣ��� ���� ��ü�� ������ �� �����Ƿ�, ��ü �ϰ����� ���� ������.
//          �߰������� ����ؾ� �Ǵ� ������ ����. - ������ ������
int main()
{
	User u;
	u.setId("chansik.yun");
	u.setLevel(10);
	u.setExp(300);
	u.setGold(1000);
	u.setCash(50);
}
