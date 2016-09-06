// 3_컨테이너
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;

	node(int a, node* n) : data(a), next(n) {}
};

class slist
{
	node* head;
public:
	slist() : head(0) {}

	// node의 생성자를 잘 활용한 코드 입니다.
	void push_front(int a)
	{  head = new node(a, head); }

	int front() { return head->data; }
};

// http://d.pr/n/1bu1m
int main()
{
	slist s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	cout << s.front() << endl;
}



















