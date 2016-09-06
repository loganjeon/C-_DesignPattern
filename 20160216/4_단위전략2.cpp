// 4_단위전략2
#include <iostream>
using namespace std;

// http://d.pr/n/1fHRM


// template 기반의 정책 교체 - 단위 전략(Policy Based Design)
// : 정책을 담은 코드를 컴파일 시간에 생성해내는 기술.
//  => Modern C++ Design - folly

// 장점 : 가상함수가 아닌 인라인 함수이다. 호출에 따른 성능저하가 없다.
// 단점 : Template 인자이므로 실행시간에 정책을 교체하는 것이 불가능하다.
//        컴파일 할때 정책이 결정된다.
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


