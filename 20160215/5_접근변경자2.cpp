// 5_���ٺ�����2
#include <iostream>
using namespace std;

// list�� �̹� �ֽ��ϴ�.
#include <list>

// �׷��� ����ڰ� stack�� �䱸�մϴ�.
// 1. stack�� �ٽ� ���������.
// 2. list�� �������� ����ϸ� stack�̴�. list�� ��������.
#if 0
template <typename T> class stack : private list<T>
{
public:
	inline void push(const T& a) { push_back(a); }  // �θ��� �Լ��� ����
	inline void pop()			 { pop_back(); }
	inline T&   top()            { return back(); }
};
#endif

// http://d.pr/n/2J5A
// Adapter Pattern : ���� Ŭ������ �������̽�(�Լ� �̸�) �����ؼ�
//                   ����ڰ� �䱸�ϴ� Ŭ����ó�� ���̰� �ϴ� ����.

// ���̺귯���� �����ڴ� ����ڰ� Ŭ������ ����ϱ� ���� ����� �͵�
// �߿�������, �߸� ����ϱ� ��ư� ����� �͵� �߿��ϴ�.

// private ��� : �θ� Ŭ�����κ��� ������ ���� ������
//                               (�ڽ��� ���������� ���������,)
//                �������̽��� ���� ���� �ʰڴ�.
//                               (�θ� �Լ��� �ܺη� �������� �ʰڴ�.)

// S/W ������ ��Ӱ� ������ �ִ�. => ������ �������� ����.
// C++ ǥ�� stack�� �Ʒ��� �����մϴ�. -> "stack adapter"
#include <stack>
#include <deque>
template <typename T, typename C=deque<T>> class xstack
{
	C st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline void pop()            { st.pop_back(); }
	inline T& top()              { return st.back(); }
};

#include <vector>

int main()
{
	stack<int> s2;

	stack<int, vector<int>> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);

	// s1.push_front(10);
	
	cout << s1.top() << endl;
}


