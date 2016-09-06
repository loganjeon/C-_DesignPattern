#include <iostream>
using namespace std;

// 생성자의 인자가 많을 때

// 방법 3. 빌더 패턴
//  : 점층적 생성자 패턴에 빈즈 패턴의 가독성을 더한 방법이다.
// 필요한 객체를 직접 생성하는 것이 아니라, 먼저 빌더 객체를 통해 필드를 초기화한 후
// 빌더객체를 통해 객체를 생성하는 것입니다.
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
// Effective Java - 생성자의 인자가 많다면, 빌더를 고려해라.
// 장점 : 가독성, 객체 일관성도 지킬 수 있다.
// 단점 : 객체 하나를 생성하기 위해서 별도의 객체를 생성해야 한다.
int main()
{
	User ui = User::Builder("chansik")
		.cash(10)
		.exp(1000)
		.gold(50)
		.level(3).build();
}
