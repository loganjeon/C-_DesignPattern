// 7_메멘토(Memento)

#include <iostream>
#include <vector>
using namespace std;

// http://d.pr/n/1cuYm

// Memento : 객체의 스냅샷을 보관 후 복원
// Command : 명령을 객체로 캡슐화


// 의도 : 객체의 상태를 내부적으로 저장했다가, 
//        언제라도 그때의 상태로 복구 가능하게 하는 패턴
class User
{
	int level;
	int exp;

	// 객체의 상태를 저장하기 위해 꼭 필요한 항목을 캡슐화
	struct Memento
	{
		int level, exp;
		Memento(int l, int e) : level(l), exp(e) {}
	};

	vector<Memento*> saves;
public:
	int save() {
		Memento *m = new Memento(level, exp);
		saves.push_back(m);

		return saves.size() - 1;
	}

	void load(int token) {
		Memento* m = saves[token];

		level = m->level;
		exp = m->exp;
	}
};

int main()
{
	User user;
	int token = user.save();

	//.......


	user.load(token);
}


#if 0
class User
{
	int level;
	int exp;
public:
	void set(int l, int e) {
		level = l;
		exp = e;
	}

	int getLevel() { return level; }
	int getExp() { return exp; }
};

int main()
{
	User user;
	user.set(10, 10000);
	//.....
	int lev = user.getLevel();
	int exp = user.getExp();

	user.set(lev, exp);
}
#endif