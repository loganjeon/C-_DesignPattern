// http://d.pr/n/1iso5
// http://d.pr/f/10QuC
// 7_반복자 종류
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

// 반복자 5가지 분류(Iterator category)
// - 반복자에 따라 제공되는 연산자 오버로딩이 다르다.
// 1. 입력 반복자(input)
//   :  =*p, ++
// 2. 출력 반복자(output)
//   :  *p=, ++
// 3. 전진형 반복자(foward) : slist
//   : 입출력, ++
// 4. 양방향 반복자(bidirectional) : list
//   : 입출력, ++, --
// 5. 임의접근 반복자(random access) : vector
//   : 입출력, ++, --, +, -, []

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