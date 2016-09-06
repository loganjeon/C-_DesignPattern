// CRTP
// 2. 객체의 생성 개수를 제한하는 기술
// 아래 예제는 모든 자식이 별도의 static 멤버 변수를 물려 받는 기법.
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