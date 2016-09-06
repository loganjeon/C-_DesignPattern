// 3_LineEdit2
#include <string>
#include <iostream>
using namespace std;

#include <conio.h>  // getch

// LineEdit의 validation 정책은 변경되어야 한다.

// 공통성과 가변성의 분리 
// 방법 1. 변하는 것을 가상함수화 한다. - Template Method
//  : 변하지 않는 코드(공통성)에서 변해야 하는 것(가변성)이 있다면
//    변해야 하는 것을 가상함수로 분리한다.

// http://d.pr/n/1aSi0
// 한계점
// 1. 실행 시간에 정책을 변경하는 것이 불가능하다.
// 2. 다른 클래스에서 정책을 재사용하는 것이 불가능하다.

class LineEdit
{
	string data;
public:
	virtual bool validate(char c) { return isdigit(c); }

	string getData()
	{
		data.clear();
		while (1)
		{
			char c = getch();
			if (c == 13) break;  // enter

			if (validate(c))
			{
				data.push_back(c);
				cout << c;
			}
		}

		cout << endl;
		return data;
	}
};

// 이제 정책을 변경하고 싶다면, 파생 클래스에서 가상함수를 재정의하면 된다.
class AddressEdit : public LineEdit
{
public:
	virtual bool validate(char c) { return true; }
};

int main()
{
	AddressEdit edit;
	while (1)
	{
		string s = edit.getData();
		cout << "input : " << s << endl;
	}
}