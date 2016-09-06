// http://d.pr/n/1iso5
// http://d.pr/f/10QuC
// 7_�ݺ��� ����
#include "List.h"
using namespace android;

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	List<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	auto p = find(s.begin(), s.end(), 20);

	cout << *p << endl;
}


#if 0
#include <list>
#include <vector>
#include <iostream>
using namespace std;

#include <algorithm>

// Effective STL - C++98/03

// �ݺ��� 5���� �з�(Iterator category)
// - �ݺ��ڿ� ���� �����Ǵ� ������ �����ε��� �ٸ���.
// 1. �Է� �ݺ���(input)
//   :  =*p, ++
// 2. ��� �ݺ���(output)
//   :  *p=, ++
// 3. ������ �ݺ���(foward) : slist
//   : �����, ++
// 4. ����� �ݺ���(bidirectional) : list
//   : �����, ++, --
// 5. �������� �ݺ���(random access) : vector
//   : �����, ++, --, +, -, []

int main()
{
	list<int> s = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 }; // C++11

	// sort(s.begin(), s.end());
	s.sort();

	for (auto e : s)
		cout << e << endl;

	s.push_back(10);
	s.push_back(20);
	s.push_back(30);

	auto p = find(s.begin(), s.end(), 20);
	cout << *p << endl;

}
#endif