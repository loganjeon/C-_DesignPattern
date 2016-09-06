// CRTP
// 2. ��ü�� ���� ������ �����ϴ� ���
// �Ʒ� ������ ��� �ڽ��� ������ static ��� ������ ���� �޴� ���.
// http://d.pr/n/z4z
template <typename T, int N>
class LimitMaxObject
{
public:
	LimitMaxObject()  { if (++count > 5) throw 1; }
	~LimitMaxObject() { --count; }

	static int count;
};

template <typename T, int N>
int LimitMaxObject<T, N>::count = 0;

class Mouse : public LimitMaxObject<Mouse, 5>
{
};

class Keyboard : public LimitMaxObject<Keyboard, 5>
{
};


int main()
{
	Mouse m1[3];
	Mouse m2[3];
}