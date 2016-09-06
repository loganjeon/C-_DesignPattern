#include <iostream>
using namespace std;
// 4_단위전략
// http://d.pr/n/RJaf
// 1. 동기화 여부를 인터페이스 기반의 다른 클래스로 분리하자. (전략 패턴)
// 장점 : 정책을 실행시간에 교체할 수 있다. (setSync()를 호출할 때마다 정책이 변경된다.)
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;

	virtual ~ISync() {}
};

template <typename T> class List
{
	ISync* pSync = 0;
public:
	void setSync(ISync* p) { pSync = p; }
	void push_front(const T& a)
	{
		pSync->lock();
		// ...
		pSync->unlock();
	}
};

class SingleThread : public ISync
{
public:
	virtual void lock() {}
	virtual void unlock() {}
};

class MultiThread : public ISync
{
public:
	virtual void lock() { cout << "mutex lock" << endl; }
	virtual void unlock() { cout << "mutex unlock" << endl; }
};

List<int> st; // 전역 변수

int main()
{
	st.setSync(new SingleThread);
	// st.setSync(new MultiThread);

	st.push_front(10);
}






