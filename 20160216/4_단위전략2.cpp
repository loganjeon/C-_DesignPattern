// 4_��������2
#include <iostream>
using namespace std;

// http://d.pr/n/1fHRM


// template ����� ��å ��ü - ���� ����(Policy Based Design)
// : ��å�� ���� �ڵ带 ������ �ð��� �����س��� ���.
//  => Modern C++ Design - folly

// ���� : �����Լ��� �ƴ� �ζ��� �Լ��̴�. ȣ�⿡ ���� �������ϰ� ����.
// ���� : Template �����̹Ƿ� ����ð��� ��å�� ��ü�ϴ� ���� �Ұ����ϴ�.
//        ������ �Ҷ� ��å�� �����ȴ�.
template <typename T, typename ThreadModel = SingleThread>
class List
{
	ThreadModel tm;
public:
	void push_front()
	{
		tm.lock();
		//....
		tm.unlock();
	}
};

class SingleThread
{
public:
	inline void lock() {}
	inline void unlock() {}
};

class MultiThread
{
public:
	inline void lock() { cout << "mutex lock" << endl; }
	inline void unlock() { cout << "mutex unlock" << endl; }
};

List<int> s;
List<int, SingleThread> s1;
List<int, MultiThread> s2;


int main()
{

}


