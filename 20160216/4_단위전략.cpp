#include <iostream>
using namespace std;
// 4_��������
// http://d.pr/n/RJaf
// 1. ����ȭ ���θ� �������̽� ����� �ٸ� Ŭ������ �и�����. (���� ����)
// ���� : ��å�� ����ð��� ��ü�� �� �ִ�. (setSync()�� ȣ���� ������ ��å�� ����ȴ�.)
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

List<int> st; // ���� ����

int main()
{
	st.setSync(new SingleThread);
	// st.setSync(new MultiThread);

	st.push_front(10);
}






