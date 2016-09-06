#include <iostream>
using namespace std;

// �������� ���ڰ� ���� ��

// ��� 3. ���� ����
//  : ������ ������ ���Ͽ� ���� ������ �������� ���� ����̴�.
// �ʿ��� ��ü�� ���� �����ϴ� ���� �ƴ϶�, ���� ���� ��ü�� ���� �ʵ带 �ʱ�ȭ�� ��
// ������ü�� ���� ��ü�� �����ϴ� ���Դϴ�.
class User
{
public:
	class Builder {
		const string id_;
		int level_;
		int exp_;
		int gold_;
		int cash_;
	public:
		Builder(const string& id) : id_(id) {}

		Builder& level(int v) {
			level_ = v;
			return *this;
		}

		Builder& exp(int v) {
			exp_ = v;
			return *this;
		}

		Builder& gold(int v) {
			gold_ = v;
			return *this;
		}

		Builder& cash(int v) {
			cash_ = v;
			return *this;
		}

		User build() {
			return User(*this);
		}

		friend class User;
	};

	User( Builder& builder)
		: id_(builder.id_),
		level_(builder.level_),
		exp_(builder.exp_),
		gold_(builder.gold_),
		cash_(builder.cash_) {}
private:
	const string id_;
	int level_;
	int exp_;
	int gold_;
	int cash_;
};

// http://d.pr/n/1imtz
// Effective Java - �������� ���ڰ� ���ٸ�, ������ ����ض�.
// ���� : ������, ��ü �ϰ����� ��ų �� �ִ�.
// ���� : ��ü �ϳ��� �����ϱ� ���ؼ� ������ ��ü�� �����ؾ� �Ѵ�.
int main()
{
	User ui = User::Builder("chansik")
		.cash(10)
		.exp(1000)
		.gold(50)
		.level(3).build();
}
