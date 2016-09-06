// 7_�޸���(Memento)

#include <iostream>
#include <vector>
using namespace std;

// http://d.pr/n/1cuYm

// Memento : ��ü�� �������� ���� �� ����
// Command : ����� ��ü�� ĸ��ȭ


// �ǵ� : ��ü�� ���¸� ���������� �����ߴٰ�, 
//        ������ �׶��� ���·� ���� �����ϰ� �ϴ� ����
class User
{
	int level;
	int exp;

	// ��ü�� ���¸� �����ϱ� ���� �� �ʿ��� �׸��� ĸ��ȭ
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